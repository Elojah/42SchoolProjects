type t = int list

(* Return empty  TicTac*)
val newTicTac : t

(* T before move -> move -> is valid *)
val validMove : t -> int -> bool

(* T before move -> move [0-9] -> num player -> T after move *)
val play : t -> int -> int -> t

(* T state -> 0 | num player winner *)
val win : t -> bool

val isFull : t -> bool

val getLineString : t -> int -> string

val getFirstEmpty : t -> int
(* get value in x [0-9] *)
val getValue : t -> int -> int
