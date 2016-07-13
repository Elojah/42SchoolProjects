let sum (a:float) (b:float) : float =
	a +. b

let () =
	print_float (sum 12.30 56.482);print_char '\n';
	print_float (sum 78.3570 5.782);print_char '\n';
	print_float (sum (-78.3570) 0.0);print_char '\n'
