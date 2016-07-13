let iter f x n =
	let rec loop_n f res n =
		if n = 0 then res
		else loop_n f (f res) (n - 1)
	in
	loop_n f x n

let main () =
	print_int (iter (fun x -> x * x) 2 4);
	print_char '\n';
	print_int (iter (fun x -> x * 2) 2 4);
	print_char '\n'

(**********************************)

let () = main ()
