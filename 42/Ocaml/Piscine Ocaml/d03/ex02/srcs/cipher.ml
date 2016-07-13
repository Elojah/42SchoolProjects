let rot42 str =
	let rot_alpha c =
		if (c >= 'a' && c <= 'z') then
			char_of_int(((int_of_char c) + 16 - int_of_char 'a') mod 26 + int_of_char 'a')
		else if (c >= 'A' && c <= 'Z') then
			char_of_int(((int_of_char c) + 16 - int_of_char 'A') mod 26 + int_of_char 'A')
		else
			c
	in
	String.map rot_alpha str

let caesar str n =
	let true_n = if n < 0 then 26 - ((-n) mod 26)
			else n mod 26
	in
	let rot_alpha c =
		if (c >= 'a' && c <= 'z') then
			char_of_int(((int_of_char c) + true_n - int_of_char 'a') mod 26 + int_of_char 'a')
		else if (c >= 'A' && c <= 'Z') then
			char_of_int(((int_of_char c) + true_n - int_of_char 'A') mod 26 + int_of_char 'A')
		else
			c
	in
	String.map rot_alpha str

let xor str key =
	let xor_alpha c = char_of_int ((int_of_char c) lxor key)
	in
	String.map xor_alpha str

let ft_crypt str fs =
	let rec loop_fs fs acc = match fs with
		| [] -> acc
		| crt::next -> loop_fs next (crt acc)
	in
	loop_fs fs str

let () =
	let test = "TEST"
	in
	(
		print_endline "Original str:";
		print_endline test;
		print_endline "42 str:";
		print_endline (rot42 test);
		print_endline "un42 str:";
		print_endline (Uncipher.unrot42 (rot42 test));
		print_endline "c str:";
		print_endline (caesar test 42);
		print_endline "unc str:";
		print_endline (Uncipher.uncaesar (caesar test 42) (42));
		print_endline "xor str:";
		print_endline (xor test 42);
		print_endline "unxor str:";
		print_endline (Uncipher.unxor (xor test 42) (42));
		let lst_f = [fun str -> xor str 3] @ [rot42] @ [rot42] @ [rot42]
		and lst_f_rev = [Uncipher.unrot42] @ [Uncipher.unrot42] @ [Uncipher.unrot42] @ [fun str -> xor str 3]
		in
		(
			print_endline "crypt str:";
			print_endline (ft_crypt test lst_f);
			print_endline "uncrypt str:";
			print_endline (Uncipher.ft_uncrypt (ft_crypt test lst_f) lst_f_rev)
		)
	)
