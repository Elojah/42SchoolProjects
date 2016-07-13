let repeat_x n =
	let rec loop_i i s =
		if i > 0 then
			loop_i (i - 1) (s ^ "x")
		else
			s
	in
	loop_i n ""

let main () =
	print_endline (repeat_x 5);
	print_endline (repeat_x 50);
	print_endline (repeat_x (-1));
	print_endline (repeat_x 0);
	print_endline (repeat_x 500)

(**********************************)

let () = main ()
