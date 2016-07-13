(*
◦ A name attribute of type string randomly generated with the format : DalekXXX
with XXX is a random set of chars (DalekSec for example).
◦ An hp attribute of type int initialized to 100.
◦ A shield attribute of type bool mutable, initialized to true and change it’s
value each time the exterminate method is used.
◦ A to_string method that returns the name of the object with attributes values.
◦ A talk method that randomly prints one of the following strings on the standard
output :
∗ Explain! Explain!
∗ Exterminate! Exterminate!
∗ I obey!
∗ You are the Doctor! You are the enemy of the Daleks!
◦ A method exterminate which takes an argument of type people object and kill
it instantly.
◦ A method die which prints the following sentence on the standard output :
Emergency Temporal Shift!
*)

class dalek =
	object (self)
		initializer Random.self_init(); print_endline "Welcome Dalek !"
		val _name = let r = (Random.int 26, Random.int 26, Random.int 26) in
					match r with (a, b, c) ->
					"Dalek" ^ String.make 1 (char_of_int (a + 97)) ^ String.make 1 (char_of_int (b + 97)) ^ String.make 1 (char_of_int (c + 97))
		val _hp = 100
		val mutable _shield = true
		method to_string = let shield_to_str = match _shield with
							| true -> "a"
							| false -> "no"
							in
							_name ^ " still got " ^ string_of_int _hp ^ " hp and " ^ shield_to_str ^ " shield"
		method talk = let r = Random.int 3 in
						let s = match r with
						| 0 -> "Explain! Explain!"
						| 1 -> "Exterminate! Exterminate!"
						| 2 -> "I obey!"
						| _ -> "You are the Doctor! You are the enemy of the Daleks!"
						in print_endline s
		method exterminate (p:People.people) = p#die; _shield <- not _shield
		method die = print_endline "Emergency Temporal Shift!"
	end
