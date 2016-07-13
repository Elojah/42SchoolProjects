type t = TicTac.t list

let newBoard =
	let rec loop_i i acc =
		if i = 0 then acc
		else loop_i (i - 1) (acc @ [TicTac.newTicTac])
	in
	loop_i 9 []

let validMove (this:t) (block:int) (x:int) : bool =
	let rec loop_this this block i = match this with
		| [] -> invalid_arg "validMove out of range"
		| crt::next -> 	if block = i then (TicTac.validMove crt x)
						else loop_this next block (i + 1)
	in
	loop_this this block 0

let getTicTac (this:t) (x:int) : TicTac.t =
	let rec loop_this this x i = match this with
		| [] -> invalid_arg "getTicTac out of range"
		| crt::next -> 	if i = x then crt
				else loop_this next x (i + 1)
	in
	loop_this this x 0

let getTicTacString (this:t) (i:int) : string =
	TicTac.getLineString (getTicTac this ((3 * (i / 9)) + (i mod 3))) ((i / 3) mod 3)

let toString (this:t) : string =
	let rec loop_i i acc =
		if i = 27 then acc ^ "\n"
		else if (i <> 26 && i mod 9 = 8) then loop_i (i + 1) (acc ^ getTicTacString this i ^ "\n___________\n")
		else if (i mod 3 = 2) then loop_i (i + 1) (acc ^ getTicTacString this i ^ "\n")
		else loop_i (i + 1) (acc ^ getTicTacString this i ^ "|")
	in
	loop_i 0 ""

let winAlignment (a:TicTac.t) (b:TicTac.t) (c:TicTac.t) : bool =
	(TicTac.getValue a 0 = 10 || TicTac.getValue a 0 = 11)
	&& TicTac.getValue a 0 = TicTac.getValue b 0
	&& TicTac.getValue b 0 = TicTac.getValue c 0

let win (this:t) : bool =
	let rec loop_this this = match this with
		| [] -> false
		| a::b::c::_::_::_::_::_::_ when winAlignment a b c -> true
		| _::_::_::a::b::c::_::_::_ when winAlignment a b c -> true
		| _::_::_::_::_::_::a::b::c::next when winAlignment a b c -> true
		| a::_::_::b::_::_::c::_::_ when winAlignment a b c -> true
		| _::a::_::_::b::_::_::c::_ when winAlignment a b c -> true
		| _::_::a::_::_::b::_::_::c::next when winAlignment a b c -> true
		| _::_::a::_::b::_::c::_::_ when winAlignment a b c -> true
		| a::_::_::_::b::_::_::_::c::next when winAlignment a b c -> true
		| _ -> false
	in
	loop_this this

let play (this:t) (block:int) (x:int) (p:int) : t * bool =
	let rec loop_this this block i acc = match this with
		| [] -> acc
		| crt::next -> 	if i = block then loop_this next block (i + 1) (acc @ [TicTac.play crt x p])
						else loop_this next block (i + 1) (acc @ [crt])
	in
	let result = loop_this this block 0 []
	in
	if win result then (result, true)
	else (result, false)

let isFull (this:t) : bool =
	let rec loop_this this = match this with
		| [] -> true
		| crt::next when TicTac.isFull crt -> loop_this next
		| crt::next -> false
	in
	loop_this this

let gameLoop (this:t) p1 p2 display =
	if (display) then
		(
			UserInterface.init;
			UserInterface.display this;
		)
	else
		print_string (toString this);
	let rec doMove (this:t) (nBlock:int) (nTicTac:int) (p:int) =
		if validMove this nBlock nTicTac then
			(
				let freshBoard = play this nBlock nTicTac (p + 1)
				in
				match freshBoard with
				| (a, b) ->
					 (
						 if (display = false) then
							 print_string (toString a)
						 else
							 UserInterface.display a;
						 if b = false then
							 loop a ((p + 1) mod 2)
						 else if p = 0 then
							 (
								 print_string (toString a);
								 print_endline ("Player " ^ p1 ^ " has win !")
							 )
						 else if p = 1 then
							 (
								 print_string (toString a);
								 print_endline ("Player " ^ p2 ^ " has win !")
							 )
					 )
			)
		else if isFull this then (
			 if p = 0 then
				 (
					 print_string (toString this);
					 print_endline ("Player " ^ p2 ^ " has win !")
				 )
			 else if p = 1 then
				 (
					 print_string (toString this);
					 print_endline ("Player " ^ p1 ^ " has win !")
				 )
		)
		else (
				print_endline "Illegal move.";
				loop this p
			)
	and
	loop (this:t) (p:int) =
		if p = 0 then print_endline (p1 ^ " turn: \t")
		else print_endline (p2 ^ " turn: \t");
		if p = 0 && (p1 = "AI") then (
			let (nBlock, nTicTac) = IA.searchCoord this
			in Parser.print_coord_int (nBlock, nTicTac);print_char '\n'; doMove this nBlock nTicTac p
		)
		else (
			if (display = false) then
				let coord = Parser.parse_line (read_line ())
				in
				if (Parser.is_coord_string coord) then
					let (nBlock, nTicTac) = Parser.parse_value coord
					in doMove this nBlock nTicTac p
				else
					(
						print_endline "Incorrect format.";
						loop this p
					)
			else
				let (nBlock, nTicTac) = UserInterface.getCoord ()
				in
				if (nBlock = -1) then
					()
				else
					doMove this nBlock nTicTac p
		)
	in
	print_endline "\nREADY? FIGHT!\n";
	loop this 1
