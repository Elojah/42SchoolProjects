class people =
	object (self)
		val _name = "Lambda"
		val _hp = 100
		initializer print_endline ("Welcome " ^ _name ^ ", enjoy your " ^ (string_of_int _hp))
		method to_string = _name ^ " still got " ^ (string_of_int _hp)
		method talk = print_endline ("I’m " ^ _name ^"! Do you know the Doctor?")
		method die = print_endline ("Aaaarghh!")
	end
