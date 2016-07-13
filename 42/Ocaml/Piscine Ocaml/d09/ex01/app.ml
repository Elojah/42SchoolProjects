module type App =
sig
	type project = string * string * int
	val zero : project
	val combine : project -> project -> project
	val fail : project -> project
	val success : project -> project
	val print_proj : project -> unit
end

module App : App =
struct
	type project = string * string * int
	let zero = ("", "", 0)
	let combine (a:project) (b:project) : project =
		match a with (aa, ba, ca) ->
		match b with (ab, bb, cb) ->
		match (ca + cb) / 2 with
		| x when x > 80 -> (aa ^ ab, "succeed", x)
		| x -> (aa ^ ab, "failed", x)
	let fail (x:project) : project = match x with (a, _, _) -> (a, "failed", 0)
	let success (x:project) : project = match x with (a, _, _) -> (a, "succeed", 80)
	let print_proj (x:project) = match x with (a, b, c) ->
								print_endline ("Project:\t" ^ a ^ "\nStatus:\t" ^ b ^ "\nGrade:\t" ^ string_of_int c)
end
