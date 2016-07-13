type t = TicTac.t list

val newBoard : t

val getTicTac : t -> int -> TicTac.t

val toString : t -> string

val gameLoop : t -> string -> string -> bool -> unit
