let file_to_array filename : 'a array =
	let lines = ref [] in
		let chan = open_in filename in
		try
			while true; do
				lines := input_line chan :: !lines
			done; [||]
		with End_of_file -> close_in chan;
	Array.of_list (List.rev !lines)

let () =
	if (Array.length (Sys.argv) <> 2) then
		print_endline "Usage: ./a.out filename:string"
	else (
		Random.self_init ();
		let my_jokes_array = try
			file_to_array Sys.argv.(1)
		with | Sys_error e -> print_endline ("Error occured:\t" ^ e); [||]
		in
		let len = Array.length my_jokes_array in match len with
			| 0 -> print_endline ("File is empty")
			| _ -> print_endline (Array.get my_jokes_array (Random.int len))
	)
