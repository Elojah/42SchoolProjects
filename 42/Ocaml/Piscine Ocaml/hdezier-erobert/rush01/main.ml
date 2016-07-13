let rec game_loop (foxy:Creature.creature) =
	let rec depleted (foxy_depleted:Creature.creature) crt_time =
		(* print_endline foxy_depleted#to_string; *)
		UserInterface.display foxy_depleted;
		if foxy_depleted#dead then (print_endline "You killed him you bastard !"; ())
		else
		match (Unix.gettimeofday() -. crt_time) with
		| x when x < 1.0 ->
			 (
				 flush stdout;
			 	 match (UserInterface.getEvent ()) with
				 | UserInterface.Eat -> depleted foxy_depleted#eat crt_time
				 | UserInterface.Thunder -> depleted foxy_depleted#thunder crt_time
				 | UserInterface.Bath -> depleted foxy_depleted#bath crt_time
				 | UserInterface.Kill -> depleted foxy_depleted#kill crt_time
				 | UserInterface.Pet -> depleted foxy_depleted#pet crt_time
				 | UserInterface.Save ->
						(
							foxy_depleted#save_to_file "save/save.itama";
							depleted foxy_depleted crt_time
						)
				 | UserInterface.Quit -> ()
				 | _ -> depleted foxy_depleted crt_time
			 )
		| _ -> depleted (foxy_depleted#deplet) (Unix.gettimeofday())
	in
	depleted foxy (Unix.gettimeofday())

let exec : Creature.creature =
	if (Array.length (Sys.argv) = 1) then new Creature.fox "FOXY"
	else try ((new Creature.fox "Tmp object")#load_from_file Sys.argv.(1))
	with Sys_error e -> print_endline e; new Creature.fox "FOXY"

let () =
	let foxy = exec in
	UserInterface.init foxy;
	try game_loop (foxy :> Creature.creature) with
		| Invalid_argument e -> print_endline e; Graphics.close_graph ()
		| Sys_error e -> print_endline e; Graphics.close_graph ()
		| e -> Graphics.close_graph ()
