let () = let rec print_colors color_value = match color_value with
		| [] -> ()
		| crt::next -> (
			print_endline (Color.toStringVerbose crt);
			print_colors next
		)
	in
	print_colors Color.all

