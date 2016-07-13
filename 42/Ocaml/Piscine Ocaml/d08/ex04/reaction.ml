class virtual reaction (start_list:(Molecule.molecule * int) list)
						(end_list:(Molecule.molecule * int) list) =
	object (self)
		method virtual get_start : (Molecule.molecule * int) list
		method virtual get_result : (Molecule.molecule * int) list
		method virtual balance : reaction
		method virtual is_balanced : bool
		method virtual to_string : string
	end

class alkane_combustion (alkane_lst:Alkane.alkane list) =
	object (self)

		val _alk_lst = alkane_lst

		method private count_hydrogen =
			let rec loop_lst lst acc = match lst with
				| [] -> acc
				| crt::next -> loop_lst next (acc + ((2 * crt#n) + 2))
			in
			loop_lst _alk_lst 0

		method private count_carbon =
			let rec loop_lst lst acc = match lst with
				| [] -> acc
				| crt::next -> loop_lst next (acc + crt#n)
			in
			loop_lst _alk_lst 0

		method private alkane_combustion_to_reaction : ((Molecule.molecule * int) list) =
			let rec is_in_lst lst elt = match lst with
				| [] -> false
				| (a, b)::next -> a#formula = elt#formula || is_in_lst next elt
				in
			let rec count_elt lst elt acc = match lst with
				| [] -> acc
				| crt::next when crt#formula = elt#formula -> count_elt next elt (acc + 1)
				| _::next -> count_elt next elt acc
				in
			let rec loop_lst lst all_list acc = match lst with
				| [] -> acc
				| crt::next when is_in_lst acc crt -> loop_lst next all_list acc
				| crt::next -> loop_lst all_list next (acc @ [((crt :> Molecule.molecule), count_elt all_list crt 0)])
				in
			let nb_dioxygen = self#count_carbon + (self#count_hydrogen / 4)
			in
			loop_lst _alk_lst _alk_lst [(new Molecule.dioxygen, nb_dioxygen)]

		method private count_molecule_list init_lst : ((Molecule.molecule * int) list) =
			let rec is_in_lst lst elt = match lst with
				| [] -> false
				| (a, b)::next -> a#formula = elt#formula || is_in_lst next elt
				in
			let rec count_elt lst elt acc = match lst with
				| [] -> acc
				| crt::next when crt#formula = elt#formula -> count_elt next elt (acc + 1)
				| _::next -> count_elt next elt acc
				in
			let rec loop_lst lst all_list acc = match lst with
				| [] -> acc
				| crt::next when is_in_lst acc crt -> loop_lst next all_list acc
				| crt::next -> loop_lst all_list next (acc @ [((crt :> Molecule.molecule), count_elt all_list crt 0)])
				in
			loop_lst init_lst init_lst []

		method get_start : ((Molecule.molecule * int) list) = match self#is_balanced with
			| true -> self#alkane_combustion_to_reaction
			| false -> invalid_arg "Alkane list is not balanced."

		method get_result : ((Molecule.molecule * int) list) = match self#is_balanced with
			| false -> invalid_arg "Alkane list is not balanced."
			| true -> ([(new Molecule.water, self#count_hydrogen / 2)]
						@[(new Molecule.carbon_dioxyde, self#count_carbon)])
		method balance : reaction = match self#is_balanced with
			| true -> ({<_alk_lst = _alk_lst>} :> reaction)
			| false ->
				let rec loop_lst lst acc = match lst with
					| [] -> acc
					| crt::next when (crt#n * 2 + 2) mod 4 <> 0
						&& (crt#n < acc#n || (acc#n * 2 + 2) mod 4 = 0) -> loop_lst next crt
					| crt::next -> loop_lst next acc
				in
				let result = new alkane_combustion (_alk_lst @ [loop_lst _alk_lst (List.hd _alk_lst)]) in
				(result :> reaction)

		method is_balanced : bool =
			let nb_hydrogen = self#count_hydrogen in
			nb_hydrogen mod 4 = 0

		method to_string =
			let rec tuple_list_to_string lst acc = match lst with
				| [] -> acc
				| (a, b)::next -> tuple_list_to_string next (acc ^ string_of_int b ^ "->" ^ a#to_string ^ " ")
			in
			let str_result = tuple_list_to_string self#get_start "" in
			let str_final = tuple_list_to_string self#get_result "" in
			"Reaction:\t" ^ str_result ^ " = " ^ str_final

	end
