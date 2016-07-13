type 'a ft_ref = {mutable contents: 'a;}
(*
• return: ’a -> ’a ft_ref: creates a new reference.
• get: ’a ft_ref -> ’a: Dereferences a reference.
• set: ’a ft_ref -> ’a -> unit: Assign a reference’s value.
• bind: ’a ft_ref -> (’a -> ’b ft_ref) -> ’b ft_ref:
This one is a bit more
complicated. It applies a function to a reference to transform it. You can see it as
a more complicated set function
 *)

let return a = {contents = a}
let get a_ref = a_ref.contents
let set a_ref a_new = a_ref.contents <- a_new
let bind a_ref f_ref = f_ref (get a_ref)

let test_str =
	let my_ref_str = return "ABC" in (
		print_string (get my_ref_str); print_char '\n';
		set my_ref_str "DEF";
		print_string (get my_ref_str); print_char '\n';
		print_string (get (bind my_ref_str (fun a -> return ("This is new ! " ^ a)))); print_char '\n';
		print_string (get my_ref_str); print_char '\n'
	)

let () =
	let my_ref = return 5 in (
		print_int (get my_ref); print_char '\n';
		set my_ref 18;
		print_int (get my_ref); print_char '\n';
		print_int (get (bind my_ref (fun a -> return (3 * a)))); print_char '\n';
		print_int (get my_ref); print_char '\n';
		test_str
	)
