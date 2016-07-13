let () =
	print_endline (string_of_int (Watchtower.Watchtower.add 5 (-59)));
	print_endline (string_of_int (Watchtower.Watchtower.add 5 (-3)));
	print_endline (string_of_int (Watchtower.Watchtower.sub 5 0));
	print_endline (string_of_int (Watchtower.Watchtower.sub (-8) 12))
