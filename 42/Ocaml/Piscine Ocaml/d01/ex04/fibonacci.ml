let fibonacci n =
	if n < 0 then -1
	else
	let rec fib_aux n a b =
		if n = 0 then a
		else if n = 1 then b
		else fib_aux (n - 1) b (a + b)
	in
	fib_aux n 0 1

let main () =
	print_int (fibonacci (-1));
	print_char '\n';
	print_int (fibonacci 0);
	print_char '\n';
	print_int (fibonacci 1);
	print_char '\n';
	print_int (fibonacci 2);
	print_char '\n';
	print_int (fibonacci 3);
	print_char '\n';
	print_int (fibonacci 4);
	print_char '\n';
	print_int (fibonacci 25);
	print_char '\n'
(**********************************)

let () = main ()
