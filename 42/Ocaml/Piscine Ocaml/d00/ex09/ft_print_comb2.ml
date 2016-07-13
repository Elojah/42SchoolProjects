let ft_print_comb2 () =
	let print_digits2 i j =
		if i < 10 then
			print_int 0;
		print_int i;
		print_char ' ';
		if j < 10 then
			print_int 0;
		print_int j;
		if i != 98 || j != 99 then
		begin
			print_char ',';
			print_char ' '
		end
		else
			print_char '\n'
	in

	let rec loop_j i j =
		if j < 100 then
			begin
				print_digits2 i j;
				loop_j i (j + 1)
			end
	in

	let rec loop_i i =
		if i < 99 then
			begin
				loop_j i (i + 1);
				loop_i (i + 1)
			end
	in
	loop_i 0

let main () =
	ft_print_comb2 ()

(********************************************************)
let () = main()
