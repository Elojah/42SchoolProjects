type t = int list

let newTicTac =
	let rec loop_i i acc =
		if i = 9 then acc
		else loop_i (i + 1) (acc @ [0])
	in
	loop_i 0 []

let validMove (this:t) (x:int) : bool =
	let rec loop_this this x i = match this with
		| [] -> invalid_arg "validMove out of range"
		| crt::next -> 	if x = i then crt = 0
						else loop_this next x (i + 1)
	in
	loop_this this x 0

(*
X1 ->
\ /
 x
/ \
O2 ->
/ \
| |
\ /
10 -> "\\"
11 -> "/"
12 -> " "
13 -> "x"
14 -> "|"
15 -> "-"
*)

let winTicTac (p:int) =
	let rec winX i acc = match i with
		| 0 | 8 -> winX (i + 1) (acc @ [10])
		| 1 | 3 | 5 | 7 -> winX (i + 1) (acc @ [12])
		| 2 | 6 -> winX (i + 1) (acc @ [11])
		| 4 -> winX (i + 1) (acc @ [13])
		| _ -> acc
	in
	let rec winO i acc = match i with
		| 0 | 8 -> winO (i + 1) (acc @ [11])
		| 3 | 5 -> winO (i + 1) (acc @ [14])
		| 1 | 7 -> winO (i + 1) (acc @ [15])
		| 2 | 6 -> winO (i + 1) (acc @ [10])
		| 4 -> winO (i + 1) (acc @ [12])
		| _ -> acc
	in
	if p = 1 then winX 0 [] else winO 0 []

let isFull (this:t) : bool =
	let rec loop_this this = match this with
		| [] -> true
		| crt::next when crt <> 0 -> loop_this next
		| crt::next -> false
	in
	loop_this this

let win (this:t) : bool =
	let rec loop_this this = match this with
		| [] -> false
		| a::b::c::_::_::_::_::_::_ when a <> 0 && a = b && b = c -> true
		| _::_::_::a::b::c::_::_::_ when a <> 0 && a = b && b = c -> true
		| _::_::_::_::_::_::a::b::c::next when a <> 0 && a = b && b = c -> true
		| a::_::_::b::_::_::c::_::_ when a <> 0 && a = b && b = c -> true
		| _::a::_::_::b::_::_::c::_ when a <> 0 && a = b && b = c -> true
		| _::_::a::_::_::b::_::_::c::next when a <> 0 && a = b && b = c -> true
		| _::_::a::_::b::_::c::_::_ when a <> 0 && a = b && b = c -> true
		| a::_::_::_::b::_::_::_::c::next when a <> 0 && a = b && b = c -> true
		| _ -> false
	in
	(loop_this this) || (isFull this)

let play (this:t) (x:int) (p:int) : t =
	let rec loop_this this x i acc = match this with
		| [] -> acc
		| crt::next when i = x -> loop_this next x (i + 1) (acc @ [p])
		| crt::next -> loop_this next x (i + 1) (acc @ [crt])
	in
	let result = loop_this this x 0 []
	in
	if win result then winTicTac p
	else result

let toCharValue (x:int) : string = match x with
	| 0 -> "-"
	| 1 -> "X"
	| 2 -> "O"
	| 10 -> "\\"
	| 11 -> "/"
	| 12 -> " "
	| 13 -> "X"
	| 14 -> "|"
	| 15 -> "-"
	| _ -> "?"

let getLineString (this:t) (x:int) : string =
	let rec loop_this this x i acc = match this with
		| [] -> if x = 2 then acc else invalid_arg "getLine out of range"
		| crt::next when i >= (x * 3) && i < (x * 3 + 3) -> loop_this next x (i + 1) (acc ^ toCharValue crt)
		| crt::next when i = x * 3 + 3 -> acc
		| crt::next -> loop_this next x (i + 1) acc
	in
	loop_this this x 0 ""

let getFirstEmpty (this:t) : int =
	let rec loop_this this i = match this with
		| [] -> (-1)
		| crt::next when crt = 0 -> i
		| crt::next -> loop_this next (i + 1)
	in
	loop_this this 0

let getValue (this:t) (x:int) : int =
	let rec loop_this this x i = match this with
		| [] -> invalid_arg "getValue out of range"
		| crt::next when i = x -> crt
		| crt::next -> loop_this next x (i + 1)
	in
	loop_this this x 0
