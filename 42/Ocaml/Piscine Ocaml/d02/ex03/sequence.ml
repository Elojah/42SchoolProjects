let sequence n =

	let seq_0 = ["1"]
	in

	let rec convert_list_to_string lst = match lst with
		| [] -> ""
		| crt::next -> crt ^ convert_list_to_string next
	in

	let rec count_nb_occs lst elt = match lst with
	| [] -> 1
	| crt::next -> if elt <> crt then 1
				   else 1 + (count_nb_occs next elt)
	in

	let rec incr_seq_lst lst last_elt = match lst with
	| [] -> []
	| crt::next -> if crt = last_elt then incr_seq_lst next last_elt
				   else
					[string_of_int (count_nb_occs next crt)] @
					[crt] @
					incr_seq_lst next crt
	in

	let rec loop_seq n lst =
		if n < 0 then []
		else if n = 0 then lst
		else loop_seq (n - 1) (incr_seq_lst lst "")
	in
	convert_list_to_string (loop_seq (n - 1) seq_0)


(*  *)
let () =
	if (Array.length (Sys.argv) <> 2) then
		print_endline "Need int for argv"
	else
		print_endline (sequence (int_of_string Sys.argv.(1)))
