module type Watchtower =
sig
	type hour = int
	val zero : hour
	val add : hour -> hour -> hour
	val sub : hour -> hour -> hour
end

module Watchtower : Watchtower =
struct
	type hour = int
	let zero : hour = 12
	let add (a:hour) (b:hour) : hour = (((a mod zero) + (b mod zero)) + zero * 2) mod zero
	let sub (a:hour) (b:hour) : hour = (((a mod zero) - (b mod zero)) + zero * 2) mod zero
end
