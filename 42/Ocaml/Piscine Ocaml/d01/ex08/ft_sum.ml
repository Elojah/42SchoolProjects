let ft_sum f i n =
	if i > n then (-1.0)
	else
	let rec loop_n f res i =
		if i > n then res
		else loop_n f (res +. (f i)) (i + 1)
	in
	loop_n f 0.0 i

let main () =
	print_float (ft_sum (fun i -> float_of_int (i * i)) 1 100);
	print_char '\n';
	print_float (ft_sum (fun i -> float_of_int (i * i)) 10 1);
	print_char '\n'

(**********************************)

let () = main ()
