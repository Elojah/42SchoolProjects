let rec ft_countdown n =
	let print_digit n =
		if n <= 0 then
			print_int 0
		else print_int n;
		print_char '\n' in
	print_digit n;
	if n > 0 then
		ft_countdown (n - 1)

let main () =
	ft_countdown 15000;
	ft_countdown 5;
	ft_countdown (-5);
	ft_countdown 0

(********************************************************)
let () = main()
