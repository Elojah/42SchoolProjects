let ft_rot_n n str =
	let n = n
	in
	let rot_alpha c =
		if (c >= 'a' && c <= 'z') then
			char_of_int(((int_of_char c) + n - int_of_char 'a') mod 26 + int_of_char 'a')
		else if (c >= 'A' && c <= 'Z') then
			char_of_int(((int_of_char c) + n - int_of_char 'A') mod 26 + int_of_char 'A')
		else
			c
	in
	String.map rot_alpha str

let main () =
	print_endline (ft_rot_n 5 "aBcDeFgHiJkL  rstuvwxyz 456?][;}")

(********************************************************)
let () = main()
