let () =
	let test = Try.Try.return "String_test" in
	let fn (s:string) : bool = String.length s > 20 in
	let result = Try.Try.filter test fn in
	print_endline (Try.Try.to_string result);
	let fla = Try.Try.return (result) in
	print_endline (Try.Try.to_string (Try.Try.flatten fla));
	let fn_error (e:exn) = match e with
		| _ -> Try.Try.return "I am recovered !"
	in
	let recovered = Try.Try.recover result fn_error in
	print_endline (Try.Try.to_string recovered);
	let fla2 = Try.Try.return (Try.Try.return "Inception ...") in
	print_endline (Try.Try.to_string (Try.Try.flatten fla2));
	print_endline "See_ya !"
