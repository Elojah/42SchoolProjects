let ft_is_palindrome s =
	let rec loop_s_half s n len =
		if n > (len / 2) || len <= 1 then
			true
		else if s.[len - n - 1] = s.[n] then
			loop_s_half s (n + 1) len
		else
			false
	in
	loop_s_half s 0 (String.length s)

let print_bool b =
	if b then
		print_endline "true"
	else
		print_endline "false"

let main () =
	print_bool (ft_is_palindrome "");
	print_bool (ft_is_palindrome "p");
	print_bool (ft_is_palindrome "po");
	print_bool (ft_is_palindrome "pol");
	print_bool (ft_is_palindrome "TeT");
	print_bool (ft_is_palindrome "TeeeLeeeT");
	print_bool (ft_is_palindrome "OoaaoO");
	print_bool (ft_is_palindrome "OoaklaoO")

(********************************************************)
let () = main()
