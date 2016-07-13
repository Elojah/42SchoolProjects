let rec print_list_string lst = match lst with
	| [] -> ()
	| head::body ->
	begin
		print_endline head;
		print_list_string body
	end

let rec print_list_tuple lst = match lst with
	| [] -> ()
	| (count, elt)::body ->
	begin
		print_int count;
		print_string " :: ";
		print_endline elt;
		print_list_tuple body
	end

(* !Display *)

let encode lst =
	let rec count_occ lst n elt = match lst with
		| [] -> n
		| crt :: next -> if crt = elt then count_occ next (n + 1) elt
									  else count_occ next n elt
	in
	let rec add_elt lst new_elt lst_tuple = match lst_tuple with
		| [] -> [(count_occ lst 0 new_elt, new_elt)]
		| (count, elt) :: next -> if new_elt = elt then []
												   else add_elt lst new_elt next
	in
	let rec loop_lst acc lst = match lst with
		| [] -> acc
		| crt :: next -> loop_lst (acc @ add_elt lst crt acc) next
	in
	loop_lst [] lst

let main () =
	let lst1 = ["raspberry"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "raspberry"; "cherry"; "tomato"; "tomato"; "tomato"]
	and lst2 = ["raspberry"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "apricot"; "raspberry"; "cherry"; "tomato"; "tomato"; "tomato"]
	in
	print_list_string lst1;
	print_list_tuple (encode lst1);
	print_list_string lst2;
	print_list_tuple (encode lst2)
(* ******* *)

let () = main ()
