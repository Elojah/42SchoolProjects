class doctor =
	object (self)
		val _name = "Who"
		val _hp = 100
		val _age = 72
		val _sidekick = new People.people
		initializer print_endline ("Welcome Doctor " ^ _name ^ ", enjoy your " ^ string_of_int _hp ^ " hp and " ^ string_of_int _age ^ " years old")
		method to_string = _name ^ " still got " ^ string_of_int _hp ^ " hp and " ^ string_of_int _age ^ " years old with his famous sk:\t" ^ _sidekick#to_string
		method talk = print_endline ("Hi ! I’m the Doctor!")
		method use_sonic_screwdriver = print_endline "Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii"
		method travel_in_time (start:int) (arrival:int) =
		print_endline "
         /-\\
    _____|#|_____
   |_____________|
  |_______________|
|||_POLICE_##_BOX_|||
 | |¯|¯|¯|||¯|¯|¯| |
 | |-|-|-|||-|-|-| |
 | |_|_|_|||_|_|_| |
 | ||~~~| | |¯¯¯|| |
 | ||~~~|!|!| O || |
 | ||~~~| |.|___|| |
 | ||¯¯¯| | |¯¯¯|| |
 | ||   | | |   || |
 | ||___| | |___|| |
 | ||¯¯¯| | |¯¯¯|| |
 | ||   | | |   || |
 | ||___| | |___|| |
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
 ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯";
		{<_name = _name; _hp = _hp;_age = _age + arrival - start; _sidekick = _sidekick>}
		method private regenerate = {<_name = _name; _hp = 100; _age = _age; _sidekick = _sidekick>}
	end
