let ft_string_all f s =
	let rec loop_s f s n =
		if n < 0 then
			true
		else
			f (String.get s n) && loop_s f s (n - 1)
	in
	loop_s f s (String.length s - 1)

let print_bool b =
	if b then
		print_endline "true"
	else
		print_endline "false"

let main () =
	let is_number c =
		c >= '0' && c <= '9'
	in
	print_bool (ft_string_all is_number "0165048940");
	print_bool (ft_string_all is_number "01650489f40");
	print_bool (ft_string_all is_number "");
	print_bool (ft_string_all is_number "d");
	print_bool (ft_string_all is_number "0")

(********************************************************)
let () = main()
