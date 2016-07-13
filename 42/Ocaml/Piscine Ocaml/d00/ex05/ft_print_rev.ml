let ft_print_rev s =
	let rec ft_print_char_rev s n =
		if n < 0 then
			print_char '\n'
		else begin
			print_char (String.get s n);
			ft_print_char_rev s (n - 1)
		end
	in
	ft_print_char_rev s ((String.length s) - 1)

let main () =
	ft_print_rev "Test !";
	ft_print_rev "";
	ft_print_rev "akfdhuasihfuai";
	ft_print_rev "OoO"

(********************************************************)
let () = main()
