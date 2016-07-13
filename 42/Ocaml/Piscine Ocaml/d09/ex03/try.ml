(*
• Success of 'a
• Failure of exn
Your monad module will implement the following functions:
• return: 'a -> 'a Try.t
Creates a Success which contains your value.
• bind: 'a Try.t -> ('a -> 'b Try.t) -> 'b Try.t
Applies a function to your monad, converting it to a Failure if your function
argument raises an exception. Your function is only applied if your monad is a
Success.
• recover: 'a Try.t -> (exn -> 'b Try.t) -> 'b Try.t
If your monad is a Failure, applies the function to it.
• filter: 'a Try.t -> ('a -> bool) -> 'a Try.t
Converts your monad to a Failure if your monad is a Success that does not satisfy
the predicate given in argument.
• flatten: 'a Try.t Try.t -> 'a Try.t
Flattens a nested Try into a simple Try. Note that a Success of Failure is a
Failure.
*)

module type Try =
sig
	type 'a t = Success of 'a | Failure of exn
	val return : 'a -> 'a t
	val bind : 'a t -> ('a -> 'b t) -> 'b t
	val recover : 'a t -> (exn -> 'a t) -> 'a t
	val filter : 'a t -> ('a -> bool) -> 'a t
	val flatten : 'a t t -> 'a t
	val to_string : 'a t -> string
end

module Try : Try =
struct
	type 'a t = Success of 'a | Failure of exn
	exception Filtered

	let return (x:'a) : 'a t = Success(x)
	let bind (x:'a t) (f: 'a -> 'b t) : 'b t = match x with
		| Failure _ as error-> error
		| Success result -> try f result with error -> Failure(error)
	let recover (x:'a t) (f: exn -> 'a t) : 'a t = match x with
		| Failure error -> f error
		| Success _ as result -> result
	let filter (x:'a t) (f: 'a -> bool) : 'a t = match x with
		| Success result when f result = false -> Failure Filtered
		| Success result as s -> s
		| Failure _ as error -> error
	let flatten (x:'a t t) : 'a t = match x with
		| Failure _ as error -> error
		| Success next -> match next with
			| Failure _ as error -> error
			| Success _ as result -> result
	let to_string (x:'a t) = match x with
		| Success _ -> "This is a success !"
		| Failure _ -> "This is a fail ..."
end
