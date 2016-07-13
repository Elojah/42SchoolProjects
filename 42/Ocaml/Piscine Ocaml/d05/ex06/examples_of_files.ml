type radar = float array * string

let read_csv (line:string) : radar =
	let result_list = ref [] in
	let splitted_line = Str.split (Str.regexp "[,\t]+") line in
	let len = (List.length splitted_line) - 2 in
	for i = 0 to len do
		result_list := float_of_string (List.nth splitted_line i) :: !result_list
	done;
	(Array.of_list (List.rev !result_list),
		List.nth splitted_line ((List.length splitted_line) - 1))

let examples_of_file (filename:string) : radar list =
	let result = ref [] in
		let chan = open_in filename in
		try
			while true; do
				result := (read_csv (input_line chan)) :: !result
			done;
			[([||], "None")]
		with End_of_file -> close_in chan;
	List.rev !result


(*
Compile with oo str.cmxa examples_of_file.ml
*)
let () =
	let print_array a =
		let len = Array.length a - 1 in
		for i = 0 to len do
			print_float a.(i); print_string ","
		done
	in
	try
		let result =  examples_of_file "ionosphere.test.csv" in
		let rec print_list result = match result with
			| [] -> ()
			| (a, b)::next -> print_array a; print_endline b; print_list next
		in
		print_list result
	with Sys_error e -> print_endline ("Error: " ^ e)
