let rec converges f x n =
	if n < 0 then false
	else x = f x || converges f (f x) (n - 1)

let print_bool b =
	if b then
		print_endline "true"
	else
		print_endline "false"

let main () =
	print_bool (converges (( * ) 2) 2 5);
	print_bool (converges (fun x -> x / 2) 2 3);
	print_bool (converges (fun x -> x / 2) 2 2)

(**********************************)

let () = main ()
