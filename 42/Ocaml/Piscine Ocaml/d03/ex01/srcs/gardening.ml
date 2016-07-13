type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let height t =
	let rec loop_t t = match t with
		| Nil -> 0
		| Node(v, Nil, Nil) -> 0
		| Node(v, lhs, rhs) -> 1 + (max (loop_t lhs) (loop_t rhs))
	in
	let result = loop_t t
	in
	if result = 0 then 0
	else result - 1

let size t =
	let rec loop_t t = match t with
		| Nil -> 0
		| Node(v, Nil, Nil) -> 1
		| Node(v, lhs, rhs) -> (loop_t lhs) + (loop_t rhs)
	in
	loop_t t

let draw_square x y size =
	Graphics.moveto x y;
	Graphics.lineto (x + size) y;
	Graphics.lineto (x + size) (y + size);
	Graphics.lineto x (y + size);
	Graphics.lineto x y

let draw_tree n =
	let rec loop_n node x y n size = match node with
		| Nil ->
		(
			draw_square x y size;
			Graphics.moveto (x + size / 3) (y + size / 3);
			Graphics.draw_string "Nil"
		)
		| Node(a, b, c) ->
		(
			draw_square x y size;
			Graphics.moveto (x + size / 3) (y + size / 3);
			Graphics.draw_string a;
			Graphics.moveto (x + size) (y + size);
			Graphics.lineto (x + 128) (y + n);
			loop_n b (x + 128) (y + n) (n / 2 + size) size;
			Graphics.moveto (x + size) y;
			Graphics.lineto (x + 128) (y - n + size);
			loop_n c (x + 128) (y - n) (n / 2 + size) size
		)
	in
	let x = 50
	in let y = 400
	in let size = 40
	in
	loop_n n x y 128 size

let draw () =
	let my_tree = (Node("ROOT",
				Node("0",
					Node("1",
						Nil,
						Node("2",
							Nil,
							Nil)
						),
					Nil
					),
					Node("0",
						Node("3",
							Nil,
							Node("4",
								Nil,
								Node("5",
									Nil,
									Nil)
							)
						),
						Nil
						)
				)
			)
	in
	(
		print_int (height my_tree);
		print_char '\n';
		print_int (size my_tree);
		print_char '\n';
		draw_tree my_tree
	)

let graph_loop () =
	let rec loop e = match e with
		| 'q' -> ()
		| _ -> loop (Graphics.read_key ())
	in
	loop (Graphics.read_key ())

let ft_graphics () =
	Graphics.open_graph " 1200x800";
	draw ();
	graph_loop ();
	Graphics.close_graph ()


(*  *)
let () = ft_graphics ()
