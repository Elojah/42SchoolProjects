class virtual molecule (param: string * Atom.atom list) =
	object (self)

		val _info = param

		method name = match _info with (m_name, _) -> m_name
		method formula = self#calculus_formula
		method to_string = self#name ^ ":" ^ self#calculus_formula

		method private sort_atom_list atom_list =
			let sort_fun a b = match a#symbol with
				| "C" -> (-1)
				| "H" when b#symbol <> "C" -> (-1)
				| _ -> match b#symbol with
					| "C" | "H" -> 1
					| _ -> String.compare a#symbol b#symbol
			in
			List.sort sort_fun atom_list

		method private to_string_list atom_list =
			let rec loop_lst lst acc = match lst with
				| [] -> acc
				| (a, b)::next -> match b with
					| 1 -> loop_lst next (acc ^ a#symbol)
					| _ -> loop_lst next (acc ^ a#symbol ^ string_of_int b)
			in
			loop_lst atom_list ""

		method private calculus_formula =
			let rec is_in_lst lst elt = match lst with
				| [] -> false
				| (a, b)::next -> a#atomic_number = elt#atomic_number || is_in_lst next elt
				in
			let rec count_elt lst elt acc = match lst with
				| [] -> acc
				| crt::next when crt#atomic_number = elt#atomic_number -> count_elt next elt (acc + 1)
				| _::next -> count_elt next elt acc
				in
			let rec loop_lst lst all_list acc = match lst with
				| [] -> acc
				| crt::next when is_in_lst acc crt -> loop_lst next all_list acc
				| crt::next -> loop_lst all_list next (acc @ [(crt, count_elt all_list crt 0)])
				in
			let orig_list = match _info with
				(_, m_atom_list) -> loop_lst (self#sort_atom_list m_atom_list) m_atom_list [] in
			self#to_string_list orig_list
	end

class water =
	object (self) inherit molecule ("Water", [
											new Atom.hydrogen;
											new Atom.hydrogen;
											new Atom.oxygen;
												])
	end

class carbon_dioxyde =
	object (self) inherit molecule ("Carbon Dioxyde", [
											new Atom.carbon;
											new Atom.oxygen;
											new Atom.oxygen;
												])
	end

class dihydogen =
	object (self) inherit molecule ("Dihydrogen", [
											new Atom.hydrogen;
											new Atom.hydrogen;
												])
	end

class dioxygen =
	object (self) inherit molecule ("Dioxygen", [
											new Atom.oxygen;
											new Atom.oxygen;
												])
	end

class benzene =
	object (self) inherit molecule ("Benzene", [
											new Atom.carbon;
											new Atom.carbon;
											new Atom.carbon;
											new Atom.carbon;
											new Atom.carbon;
											new Atom.carbon;
											new Atom.hydrogen;
											new Atom.hydrogen;
											new Atom.hydrogen;
											new Atom.hydrogen;
											new Atom.hydrogen;
											new Atom.hydrogen;
												])
	end
