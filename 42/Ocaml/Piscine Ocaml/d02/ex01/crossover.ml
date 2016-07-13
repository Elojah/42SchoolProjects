let crossover lst_1 lst_2 =
	let rec is_in_lst elt lst acc = match lst with
		| [] -> false
		| crt :: next -> if (crt = elt && is_in_lst elt acc [] = false) then true else is_in_lst elt next acc
	in
	let rec loop_lst lst_1 lst_2 acc = match lst_1 with
		| [] -> acc
		| crt :: next ->
			if (is_in_lst crt lst_2 acc) = true then
				loop_lst next lst_2 (acc @ [crt])
			else
				loop_lst next lst_2 acc
	in
	loop_lst lst_1 lst_2 []

(*  *)
let () =
	let rec print_list_string myList = match myList with
		| [] -> print_endline "–––––––––––––––––––––––––____----"
		| head::body ->
	begin
		print_endline head;
		print_list_string body
	end
	in
	let l1 = ["A";
		"apricot";
		"raspberry";
		"cherry";
		"tomato";
		"raspberry";
		"A";
		"A";
		"Mad Max"]
	in
	let l2 = ["A";
		"apricot";
		"raspberry";
		"A";
		"Mad Max";
		"Max"]
	in
	print_list_string l1;
	print_list_string l2;
	print_list_string (crossover l1 l2);
	print_list_string (crossover l2 l1);
	print_list_string (crossover l1 []);
	print_list_string (crossover [] l2);
	print_list_string (crossover [] [])
