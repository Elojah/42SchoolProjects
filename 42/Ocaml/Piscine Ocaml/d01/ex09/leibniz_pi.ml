let leibniz_pi delta =
	let alternate_one_neg i =
		if (i mod 2 = 0) then 1.0
		else (-1.0)
	in
	let f i = (alternate_one_neg i) /. float_of_int(2 * i + 1)
	and fabs n = if n > 0.0 then n else (n *. (-1.0))
	in
	let rec loop_delta n res =
		if (fabs (res -. (atan 1.0))) *. 4.0 < delta then n
		else loop_delta (n + 1) (res +. f n)
	in
	loop_delta 0 0.0

	(* Insert in first line of loop_delta *)
	(* print_float (4.0 *. res);print_char '\n'; *)
let main () =
	print_int (leibniz_pi 0.1);
	print_char '\n';
	print_int (leibniz_pi 0.01);
	print_char '\n';
	print_int (leibniz_pi 0.00005);
	print_char '\n';
	print_int (leibniz_pi 0.0000512);
	print_char '\n'

(**********************************)

let () = main ()
