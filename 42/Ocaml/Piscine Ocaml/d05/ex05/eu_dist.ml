let eu_dist (a: float array) (b:float array) : float =
	let result = ref 0.0 in
	let len = (Array.length a - 1)in
	for i = 0 to len do
		result := !result +. ((a.(i) -. b.(i)) *. (a.(i) -. b.(i)))
	done;
	sqrt !result

let () =
	print_float (eu_dist [|1.; 2.; 3.; 4.12|] [|7.; 6.;65.; (-7.)|]);
	print_float (eu_dist [|1.; 1.; 1.|] [|2.; 2.; 2.|]);
	let a = Array.init 3 (fun i -> float_of_int 1) in
	let b = Array.init 3 (fun i -> float_of_int 2) in
	try
		let v = eu_dist a b in
		print_float v;print_char '\n'
	with Invalid_argument e -> print_endline ("Error:\t" ^ e);

