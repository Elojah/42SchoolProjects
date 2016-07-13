let ft_print_comb () =
	let display_digit i j k =
		print_int i;
		print_int j;
		print_int k;
		if (i <> 7 || j <> 8 || k <> 9) then
			print_string ", "
		else
			print_string "\n"
	in
	let rec loop_k i j k =
		if k < 10 then
		begin
			display_digit i j k;
			loop_k i j (k + 1)
		end
	in
	let rec loop_j i j =
		if j < 10 then
		begin
			loop_k i j (j + 1);
			loop_j i (j + 1)
		end
	in
	let rec loop_i i =
		if i < 8 then
		begin
			loop_j i (i + 1);
			loop_i (i + 1)
		end
	in
	loop_i 0

let main () =
	ft_print_comb ()

(********************************************************)
let () = main()
