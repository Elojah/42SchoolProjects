let gray n =

	let gray_0 = ["0"; "1"]
	in
	let rec print_list_string lst = match lst with
		| [] -> ()
		| crt::next ->
		(
			print_string crt;
			if next <> [] then print_char ' '
			else print_char '\n';
			print_list_string next
		)
	in
	let rec insert_at_end lst i = match lst with
		| [] -> [i]
		| crt :: next -> crt :: (insert_at_end next i)
	in
	let rec append_lst lst_1 lst_2 =
		let rec append_lst_2 lst_2 = match lst_2 with
		| [] -> []
		| crt::next -> crt :: (append_lst_2 next)
		in
		match lst_1 with
			| [] -> append_lst_2 lst_2
			| crt :: next -> crt :: (append_lst next lst_2)
	in
	let rec reverse_lst lst = match lst with
		| [] -> []
		| crt::next -> insert_at_end (reverse_lst next) crt
	in
	let rec add_string_to_lst s lst = match lst with
		| [] -> []
		| crt::next -> append_lst [(s ^ crt)] (add_string_to_lst s next)
	in
	let rec incr_gray_lst lst =
		append_lst (add_string_to_lst "0" lst) (add_string_to_lst "1" (reverse_lst lst))
	in
	let rec loop_gray n lst =
		if n < 1 then []
		else if n = 1 then lst
		else loop_gray (n - 1) (incr_gray_lst lst)
	in
	print_list_string (loop_gray n gray_0)


(*  *)
let () =
	if (Array.length (Sys.argv) <> 2) then
		print_endline "Need int for argv"
	else
		gray (int_of_string Sys.argv.(1))
