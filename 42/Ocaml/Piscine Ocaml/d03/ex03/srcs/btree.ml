type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let height t =
	let rec loop_t t = match t with
		| Nil -> 0
		| Node(v, lhs, rhs) -> 1 + (max (loop_t lhs) (loop_t rhs))
	in
	loop_t t

let is_bst root =

	let rec tree_less t (n:int) = match t with
		| Nil -> true
		| Node(x, lhs, rhs) -> x < n && (tree_less lhs n) && (tree_less rhs n)
	in

	let rec tree_gtr t (n:int) = match t with
		| Nil -> true
		| Node(x, lhs,rhs) -> x > n && (tree_gtr lhs n) && (tree_gtr rhs n)
	in

	let rec loop_t t = match t with
		| Nil -> true
		| Node(x, lhs,rhs) -> loop_t lhs && loop_t rhs && (tree_less lhs x) && (tree_gtr rhs x)
	in

	loop_t root

let is_perfect root =

	let rec loop_t t n dist = match t with
		| Nil -> if n <> dist then false else true
		| Node(x, Nil, Node(_, _, _)) -> false
		| Node(x, Node(_, _, _), Nil) -> false
		| Node(x, lhs, rhs) -> (loop_t lhs (n + 1) dist) && (loop_t rhs (n + 1) dist)
	in

	loop_t root 0 (height root)


let is_balanced root =

	let abs n = if n < 0 then (-n) else n
	in
	let rec loop_t t = match t with
		| Nil -> true
		| Node(x, lhs, rhs) -> loop_t lhs && loop_t rhs && abs((height lhs) - (height rhs)) < 2
	in
	loop_t root

let search_bst root value =

	let rec loop_t t value = match t with
		| Nil -> false
		| Node(x, lhs, rhs) -> if x = value then true
					else loop_t lhs value || loop_t rhs value
	in
	loop_t root value

let add_bst root value =

	let rec loop_t t n = match t with
		| Nil -> Node(n, Nil, Nil)
		| Node(x, lhs, rhs) -> if x = n then t
					else if n < x then Node(x, loop_t lhs n, rhs)
						else Node(x, lhs, loop_t rhs n)
	in
	loop_t root value

let delete_bst root value =

	let rec tree_max t = match t with
		| Node(x, _, Nil) -> x
		| Node(_, _, rhs) -> tree_max rhs
		| _ -> failwith "tree_max called on Empty"
	in
	let rec loop_t t n = match t with
		| Nil -> Nil
		| Node(x, lhs, rhs) -> if x = n then match (lhs, rhs) with
						| (Nil, Nil) -> Nil
						| (Node _ , Nil) -> lhs
						| (Nil, Node _) -> rhs
						| _ -> let m = tree_max lhs in Node(m, loop_t lhs m, rhs)
					else if n < x then Node(x, loop_t lhs n, rhs)
					else Node(x, lhs, loop_t rhs n)
	in
	loop_t root value

(*  *)
let () =
	let my_tree = (Node(10,
			Node(5,
				Node(2,
					Nil,
					Node(4,
						Nil,
						Nil)
					),
				Nil
				),
			Node(20,
				Node(11,
					Nil,
					Node(15,
						Nil,
						Node(18,
							Nil,
							Nil)
					)
				),
				Nil
				)
			)
		)
	in
	let perfect_tree = (Node(5,
				Node(5, Nil, Nil),
				Node(5, Nil, Nil)))
	in
	(
		print_endline "__________________________________________is_bst";
		if is_bst my_tree then print_endline "This is a bst !"
		else print_endline "This is not a bst ...";
		print_endline "__________________________________________is_perfect";
		if is_perfect my_tree then print_endline "This is a perfect tree !"
		else print_endline "This is not a perfect ...";
		if is_perfect perfect_tree then print_endline "This is a perfect tree !"
		else print_endline "This is not a perfect ...";
		print_endline "__________________________________________is_balanced";
		if is_balanced my_tree then print_endline "This is a balanced tree !"
		else print_endline "This is not balanced ...";
		if is_balanced perfect_tree then print_endline "This is a balanced tree !"
		else print_endline "This is not balanced ...";
		print_endline "__________________________________________add_bst";
		if search_bst my_tree 4 then print_endline "Found value 4 in tree !"
		else print_endline "Value 4 not found ...";
		print_endline "__________________________________________search_bst";
		if search_bst perfect_tree 4 then print_endline "Found value 4 in tree !"
		else print_endline "Value 4 not found ...";
		if search_bst (add_bst perfect_tree 4) 4 then print_endline "Found value 4 in tree !"
		else print_endline "Value 4 not found ...";
		print_endline "__________________________________________delete_bst";
		if search_bst (delete_bst (my_tree) 4) 4 then print_endline "Found value 4 in tree !"
		else print_endline "Value 4 not found ..."
	)
