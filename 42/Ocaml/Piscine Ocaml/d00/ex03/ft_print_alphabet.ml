let ft_print_alphabet () =
	let rec ft_print_alpha c =
		print_char c;
		if c <> 'z' then
			ft_print_alpha (char_of_int(int_of_char(c) + 1))
		else
			print_char '\n' in
	ft_print_alpha 'a'

let main () =
	ft_print_alphabet ()

(********************************************************)
let () = main()
