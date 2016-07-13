let unrot42 str =
	let rot_alpha c =
		if (c >= 'a' && c <= 'z') then
			char_of_int(((int_of_char c) + 10 - int_of_char 'a') mod 26 + int_of_char 'a')
		else if (c >= 'A' && c <= 'Z') then
			char_of_int(((int_of_char c) + 10 - int_of_char 'A') mod 26 + int_of_char 'A')
		else
			c
	in
	String.map rot_alpha str

let uncaesar str n =
	let tmp_n = (-n)
	in
	let true_n = if tmp_n < 0 then 26 - ((-tmp_n) mod 26)
			else tmp_n mod 26
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

let unxor str key =
	let xor_alpha c = char_of_int ((int_of_char c) lxor key)
	in
	String.map xor_alpha str

let ft_uncrypt str fs =
	let rec loop_fs fs acc = match fs with
		| [] -> acc
		| crt::next -> loop_fs next (crt acc)
	in
	loop_fs fs str
