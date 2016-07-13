let repeat_string ?(s="x") n =
	let rec loop_i i result =
		if i > 0 then
			loop_i (i - 1) (result ^ s)
		else
			result
	in
	loop_i n ""

let main () =
	print_endline (repeat_string ~s:"TeSt" 5);
	print_endline (repeat_string 50);
	print_endline (repeat_string (-1));
	print_endline (repeat_string ~s:"Why" 1);
	print_endline (repeat_string ~s:"OP RAT" 500)

(**********************************)

let () = main ()
