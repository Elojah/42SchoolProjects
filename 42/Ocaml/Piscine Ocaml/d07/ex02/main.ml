let () =
	let p = new People.people in
	print_endline p#to_string;
	p#talk;
	p#die;
	let doc = new Doctor.doctor in
	print_endline doc#to_string;
	doc#talk;
	doc#use_sonic_screwdriver;
	let futur_doc = doc#travel_in_time 2015 3060 in
	print_endline (futur_doc#to_string);
	let dal = new Dalek.dalek in
	print_endline dal#to_string;
	dal#talk;
	dal#exterminate (new People.people);
	print_endline dal#to_string;
	dal#die
