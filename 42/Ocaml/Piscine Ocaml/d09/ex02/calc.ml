module type MONOID =
sig
	type element
	val zero1 : element
	val zero2 : element
	val mul : element -> element -> element
	val add : element -> element -> element
	val div : element -> element -> element
	val sub : element -> element -> element
end

module INT =
struct
	type element = int
	let zero1 = 0
	let zero2 = 1
	let mul = ( * )
	let add = ( + )
	let div = ( / )
	let sub = ( - )
end

module FLOAT =
struct
	type element = float
	let zero1 = 0.
	let zero2 = 1.
	let mul = ( *. )
	let add = ( +. )
	let div = ( /. )
	let sub = ( -. )
end

module Calc =
	functor (M : MONOID) ->
	struct
		type element = M.element
		let add (a:element) (b:element) : element = M.add a b
		let sub (a:element) (b:element) : element = M.sub a b
		let mul (a:element) (b:element) : element = M.mul a b
		let div (a:element) (b:element) : element = M.div a b
		let power (a:element) (n:int) : element =
			let rec loop_n n a acc = match n with
			| x when x < 0 -> M.zero1
			| x when x = 0 -> acc
			| _ -> loop_n (n - 1) a (M.mul acc a)
			in
			loop_n n a M.zero2
		let fact (n:element) : element =
			let rec loop_n n acc = match n with
			| x when x < M.zero1 -> M.zero1
			| x when x = M.zero1 -> acc
			| x -> loop_n (M.sub n M.zero2) (M.mul acc x)
			in
			loop_n n M.zero2
	end

module Calc_int = Calc(INT)
module Calc_float = Calc(FLOAT)
