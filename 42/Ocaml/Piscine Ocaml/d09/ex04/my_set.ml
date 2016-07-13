(*
• return: ’a -> ’a Set.t
Creates a singleton containing the value given in argument.
• bind: ’a Set.t -> (’a -> ’b Set.t) -> ’b Set.t
Applies the function to every element in the Set and returns a new set.
• union: ’a Set.t -> ’a Set.t -> ’a Set.t Returns a new set containing the
union of the two sets given in argument.
• inter: ’a Set.t -> ’a Set.t -> ’a Set.t
Returns a new set containing the intersection of the two sets given in argument.
• diff: ’a Set.t -> ’a Set.t -> ’a Set.t Returns a new set containing the
difference between the two sets given in argument.
• filter: ’a Set.t -> (’a -> bool) -> ’a Set.t
Returns a new set containing only the elements that satisfy the predicate given in
argument.
• foreach: ’a Set.t -> (’a -> unit) -> unit
Executes the function given in argument on every element in the Set.
• for_all: ’a Set.t -> (’a -> bool) -> bool
Returns true if all the elements in the set satisfy the predicate given in argument,
false otherwise.
• exists: ’a Set.t -> (’a -> bool) -> bool Returns true if at least one element
in the set satisfies the predicate given in argument, false otherwise.
*)

module type Set =
sig
	type 'a t = 'a set

	val return: 'a -> 'a t
	val bind: 'a t -> ('a -> 'b t) -> 'b t
	val union: 'a t -> 'a t -> 'a t
	val inter: 'a t -> 'a t -> 'a t
	val diff: 'a t -> 'a t -> 'a t
	val filter: 'a t -> ('a -> bool) -> 'a t
	val foreach: 'a t -> ('a -> unit) -> unit
	val for_all: 'a t -> ('a -> bool) -> bool
	val exists: 'a t -> ('a -> bool) -> bool
end

module Set : Set =
struct
	type 'a t = 'a set

	let return (x:'a) : 'a t =
	let bind 'a t -> ('a -> 'b t) -> 'b t =
	let union 'a t -> 'a t -> 'a t =
	let inter 'a t -> 'a t -> 'a t =
	let diff 'a t -> 'a t -> 'a t =
	let filter 'a t -> ('a -> bool) -> 'a t =
	let foreach 'a t -> ('a -> unit) -> unit =
	let for_all 'a t -> ('a -> bool) -> bool =
	let exists 'a t -> ('a -> bool) -> bool =
end
