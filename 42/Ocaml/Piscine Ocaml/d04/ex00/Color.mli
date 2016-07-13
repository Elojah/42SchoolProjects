type t = Spade | Heart | Diamond | Club
val all : t list (** The list of all values of type t *)
val toString : t -> string (** "S", "H", "D" or "C" *)
val toStringVerbose : t -> string (** "Spade", "Heart", etc *)
