let my_sleep () = Unix.sleep 1

let wait_for (n:int) =
	for i = 1 to n do
		my_sleep ()
	done

(*
Compile with
oo unix.cmxa micronap.ml
 *)
let () =
	if (Array.length (Sys.argv) <> 2) then
		print_endline "Usage: ./a.out n:int"
	else
		try wait_for (int_of_string Sys.argv.(1))
		with Failure "int_of_string" -> print_endline "Bad integer constant";
