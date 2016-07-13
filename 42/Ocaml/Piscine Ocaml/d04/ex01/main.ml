let () =
	let rec print_values card n = match card with
	| [] -> ()
	| crt::next -> (
		print_endline "________________________";
		print_int (Value.toInt crt);
		print_char '\n';
		print_endline (Value.toStringVerbose crt);
		print_endline "next =>";
		if n <> 13 then print_endline (Value.toStringVerbose (Value.next crt));
		print_endline "prev =>";
		if n <> 1 then print_endline (Value.toStringVerbose (Value.previous crt));
		print_endline "________________________";
		print_values next (n + 1)
	)
	in
	print_values Value.all 1
