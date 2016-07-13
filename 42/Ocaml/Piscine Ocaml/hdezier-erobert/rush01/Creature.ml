class virtual creature =
object
	method virtual name : string
	method virtual dead : bool
	method virtual health : int
	method virtual energy : int
	method virtual happiness : int
	method virtual hygien : int
	method virtual cuteness : int
	method virtual eat : creature
	method virtual thunder : creature
	method virtual bath : creature
	method virtual kill : creature
	method virtual pet : creature
	method virtual deplet : creature
	method virtual to_string : string
	method virtual save_to_file : string -> unit
	method virtual load_from_file : string -> creature
end

class fox (name:string) =
object (self)
	val _name = name
	val _health = 100
	val _energy = 100
	val _happiness = 100
	val _hygien = 100
	val _cuteness = 100

	method name = _name
	method health = max _health 0
	method energy = max _energy 0
	method happiness = max _happiness 0
	method hygien = max _hygien 0
	method cuteness = max _cuteness 0

	method dead : bool = self#health = 0
						|| self#energy = 0
						|| self#happiness = 0
						|| self#hygien = 0
						|| self#cuteness = 0


	method eat : creature = ({<_name = self#name;
					_health = min (self#health + 25) 100;
					_energy = min (self#energy - 10) 100;
					_hygien = min (self#hygien - 20) 100;
					_happiness = min (self#happiness + 5) 100;
					_cuteness = min (self#cuteness - 10) 100>} :> creature)

	method thunder : creature = ({<_name = self#name;
					_health = min (self#health - 20) 100;
					_energy = min (self#energy + 25) 100;
					_hygien = min (self#hygien ) 100;
					_happiness = min (self#happiness - 20) 100;
					_cuteness = min (self#cuteness + 5) 100>} :> creature)

	method bath : creature = ({<_name = self#name;
					_health = min (self#health - 20) 100;
					_energy = min (self#energy - 10) 100;
					_hygien = min (self#hygien + 25) 100;
					_happiness = min (self#happiness + 5) 100;
					_cuteness = min (self#cuteness + 40) 100>} :> creature)

	method kill : creature = ({<_name = self#name;
					_health = min (self#health - 20) 100;
					_energy = min (self#energy - 10) 100;
					_hygien = min (self#hygien) 100;
					_happiness = min (self#happiness + 20) 100;
					_cuteness = min (self#cuteness + 30) 100>} :> creature)

	method pet : creature = ({<_name = self#name;
					_health = min (self#health - 15) 100;
					_energy = min (self#energy - 10) 100;
					_hygien = min (self#hygien - 25) 100;
					_happiness = min (self#happiness - 20) 100;
					_cuteness = min (self#cuteness + 45) 100>} :> creature)

	method deplet : creature = ({<_name = self#name;
					_health = min (self#health - 1) 100;
					_energy = min (self#energy) 100;
					_hygien = min (self#hygien) 100;
					_happiness = min (self#happiness) 100;
					_cuteness = min (self#cuteness - 2) 100>} :> creature)

	method save_to_file (filename:string) =
		try (
			let oc = open_out filename in
			Printf.fprintf oc "%s,%d,%d,%d,%d,%d\n"
							self#name
							self#health
							self#energy
							self#happiness
							self#hygien
							self#cuteness;
			close_out oc;
		) with e -> print_endline ("Error saving in " ^ filename); raise e

	method load_from_file (filename:string) : creature =
		let ic = open_in filename in
		try (
			let line = input_line ic in
			flush stdout;
			close_in ic;
			let splitted_line = Str.split (Str.regexp "[,\t]+") line in
			let array_member = Array.of_list splitted_line in
			({<_name = array_member.(0);
					_health = min (int_of_string array_member.(1)) 100;
					_energy = min (int_of_string array_member.(2)) 100;
					_hygien = min (int_of_string array_member.(3)) 100;
					_happiness = min (int_of_string array_member.(4)) 100;
					_cuteness = min (int_of_string array_member.(5)) 100>} :> creature)
		) with e -> (close_in_noerr ic; print_endline ("Error loading file " ^ filename); raise e)

	method to_string : string = (self#name ^ ":\n\t" ^ string_of_int self#health ^ " health\n\t"
												 ^ string_of_int self#energy ^ " energy\n\t"
												 ^ string_of_int self#happiness ^ " happiness\n\t"
												 ^ string_of_int self#hygien ^ " hygien\n\t"
												 ^ string_of_int self#cuteness ^ " cuteness\n")
end
