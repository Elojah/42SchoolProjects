type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let draw_square x y size =
	Graphics.moveto x y;
	Graphics.lineto (x + size) y;
	Graphics.lineto (x + size) (y + size);
	Graphics.lineto x (y + size);
	Graphics.lineto x y

let draw_tree_node n =
	let rec loop_n node x y n size count = match node with
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
			if count <> 0 then
			(
				Graphics.moveto (x + size) (y + size);
				Graphics.lineto (x + 128) (y + n);
				loop_n b (x + 128) (y + n) (n / 2 + size) size (count - 1);
				Graphics.moveto (x + size) y;
				Graphics.lineto (x + 128) (y - n + size);
				loop_n c (x + 128) (y - n) (n / 2 + size) size (count - 1)
			)
		)
	in
	let x = 50
	and y = 400
	and size = 40
	in
	loop_n n x y 128 size 1

let draw () =
	draw_tree_node (Node("ROOT",
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
								Nil)
						),
						Nil
						)
				)
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
