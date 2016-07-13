(* __________Card___________ *)
module Card = struct
(* __________Color___________ *)
module Color = struct
	type t = Spade | Heart | Diamond | Club

	(* val all : t list * The list of all values of type t *)
	let all = [Spade; Heart; Diamond; Club]

	(* val toString : t -> string * "S", "H", "D" or "C"  *)
	let toString (x:t) : string = match x with
		| Spade -> "S"
		| Heart -> "H"
		| Diamond -> "D"
		| Club -> "C"

	(* val toStringVerbose : t -> string (** "Spade", "Heart", etc *) *)
	let toStringVerbose (x:t) : string = match x with
		| Spade -> "Spade"
		| Heart -> "Heart"
		| Diamond -> "Diamond"
		| Club -> "Club"
end

(* __________Value___________ *)
module Value = struct
	type t = T2 | T3 | T4 | T5 | T6 | T7 | T8 | T9 | T10 | Jack | Queen | King | As

	(** The list of all values of type t *)
	(* val all : t list *)
	let all = [T2; T3; T4; T5; T6; T7; T8; T9; T10; Jack; Queen; King; As]

	(** Interger representation of a card value, from 1 for T2 to 13 for As *)
	(* val toInt : t -> int *)
	let toInt (x:t) : int = match x with
		| T2 -> 1
		| T3 -> 2
		| T4 -> 3
		| T5 -> 4
		| T6 -> 5
		| T7 -> 6
		| T8 -> 7
		| T9 -> 8
		| T10 -> 9
		| Jack -> 10
		| Queen -> 11
		| King -> 12
		| As-> 13

	(** returns "2", ..., "10", "J", "Q", "K" or "A" *)
	(* val toString : t -> string *)
	let toString (x:t) : string = match x with
		| T2 -> "2"
		| T3 -> "3"
		| T4 -> "4"
		| T5 -> "5"
		| T6 -> "6"
		| T7 -> "7"
		| T8 -> "8"
		| T9 -> "9"
		| T10 -> "10"
		| Jack -> "J"
		| Queen -> "Q"
		| King -> "K"
		| As-> "A"

	(** returns "2", ..., "10", "Jack", "Queen", "King" or "As" *)
	(* val toStringVerbose : t -> string *)
	let toStringVerbose (x:t) : string = match x with
		| T2 -> "2"
		| T3 -> "3"
		| T4 -> "4"
		| T5 -> "5"
		| T6 -> "6"
		| T7 -> "7"
		| T8 -> "8"
		| T9 -> "9"
		| T10 -> "10"
		| Jack -> "Jack"
		| Queen -> "Queen"
		| King -> "King"
		| As-> "As"

	(** Returns the next value, or calls invalid_arg if argument is As *)
	(* val next : t -> t *)
	let next (x:t) : t = match x with
		| T2 -> T3
		| T3 -> T4
		| T4 -> T5
		| T5 -> T6
		| T6 -> T7
		| T7 -> T8
		| T8 -> T9
		| T9 -> T10
		| T10 -> Jack
		| Jack -> Queen
		| Queen -> King
		| King -> As
		| As-> invalid_arg "Overlflow card range"

	(** Returns the previous value, or calls invalid_arg if argument is T2 *)
	(* val previous : t -> t *)
	let previous (x:t) : t = match x with
		| T2 -> invalid_arg "Underlflow card range"
		| T3 -> T2
		| T4 -> T3
		| T5 -> T4
		| T6 -> T5
		| T7 -> T6
		| T8 -> T7
		| T9 -> T8
		| T10 -> T9
		| Jack -> T10
		| Queen -> Jack
		| King -> Queen
		| As-> King
end

type t = {
		v: Value.t;
		c: Color.t;
	}

let newCard (x:Value.t) (y:Color.t) : t = {v = x; c = y}

let allColors (x:Color.t) : t list =
	let rec loop_lst lst acc = match lst with
		| [] -> acc
		| crt::next -> loop_lst next (acc @ [(newCard crt x)])
	in loop_lst Value.all []

let allSpades : t list = allColors Color.Spade
let allHearts : t list = allColors Color.Heart
let allDiamonds : t list = allColors Color.Diamond
let allClubs : t list = allColors Color.Club

let all : t list = (allColors Color.Spade) @ (allColors Color.Heart) @ (allColors Color.Diamond) @ (allColors Color.Club)

let getValue (x:t) : Value.t = x.v
let getColor (x:t) : Color.t = x.c

let compare (x:t) (y:t) : int = Value.toInt x.v - Value.toInt y.v

let max (x:t) (y:t) : t = if Value.toInt x.v >= Value.toInt y.v then x else y
let min (x:t) (y:t) : t = if Value.toInt x.v <= Value.toInt y.v then x else y

let best (lst:t list) : t = List.fold_left max (newCard Value.T2 Color.Spade) lst

let isOf (x:t) (col:Color.t) : bool = (x.c = col)

let isSpade (x:t) : bool = isOf x Color.Spade
let isHeart (x:t) : bool = isOf x Color.Heart
let isDiamond (x:t) : bool = isOf x Color.Diamond
let isClub (x:t) : bool = isOf x Color.Club

let toString (x:t) : string = Value.toString x.v ^ Color.toString x.c

let toStringVerbose (x:t) : string = "Card(" ^ Value.toStringVerbose x.v ^ ", " ^ Color.toStringVerbose x.c ^ ")"

end

type t = Card.t list

let shuffleDeck (d:t) : t =
	Random.self_init ();
	let nd = List.map (fun c -> (Random.bits (), c)) d
	in
	let sond = List.sort compare nd
	in
	List.map snd sond

let newDeck : t = shuffleDeck Card.all

let toStringList (x:t) : string list =
	let rec loop_lst lst acc = match lst with
		| [] -> acc
		| crt::next -> loop_lst next (acc @ [Card.toString crt])
	in
	loop_lst x []

let toStringListVerbose (x:t) : string list =
	let rec loop_lst lst acc = match lst with
		| [] -> acc
		| crt::next -> loop_lst next (acc @ [Card.toStringVerbose crt])
	in
	loop_lst x []

let removeHead (x:t) : t =
	let rec loop_lst lst acc isFirst = match lst with
		| [] -> acc
		| crt::next -> if isFirst then loop_lst next acc false
				else loop_lst next (acc @ [crt]) false
	in
	loop_lst x [] true

let drawCard (x:t) : Card.t * t = (List.hd x, (removeHead x))
