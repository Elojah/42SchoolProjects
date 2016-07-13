let searchCoord (tC:TicTac.t) : int =
	let rec loop_b i = match i with
		| 9 -> (-1)
		| _ when (TicTac.getValue tC i) = 0
			&& ((TicTac.win (TicTac.play tC i 1)
				|| TicTac.win (TicTac.play tC i 2))) -> i
		| _ -> loop_b (i + 1)
	in
	loop_b 0

let searchFirstEmpty (b:Board.t) : Parser.coord_int =
	let rec loop_b b i = match b with
		| [] -> invalid_arg "IA cant't play anymore ..."
		| crt::next -> let result = TicTac.getFirstEmpty crt
						in
						if result <> (-1) then (i, result)
						else loop_b next (i + 1)
		in
		loop_b b 0

let searchCoord (b:Board.t) : Parser.coord_int =
	let rec loop_tC tC i = match tC with
		| [] -> searchFirstEmpty b
		| crt::next when TicTac.isFull crt -> loop_tC next (i + 1)
		| crt::next -> let result = searchCoord crt
						in
						if result <> (-1) then (i, result)
						else loop_tC next (i + 1)
		in
		loop_tC b 0
