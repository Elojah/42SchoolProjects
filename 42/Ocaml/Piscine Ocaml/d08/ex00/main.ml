let () =
	let atom_list = [new Atom.hydrogen; new Atom.carbon; new Atom.oxygen; new Atom.boron; new Atom.sodium; new Atom.platinum; new Atom.fluorine; new Atom.vanadium]
	in
	let rec show_list lst = match lst with
	| [] -> ()
	| crt::next -> print_endline crt#to_string; show_list next
	in
	show_list atom_list
