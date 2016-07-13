let rec show_list lst = match lst with
	| [] -> ()
	| crt::next -> print_endline crt#to_string; show_list next

let () =
	let atom_list = [new Atom.hydrogen;
		new Atom.carbon;
		new Atom.oxygen;
		new Atom.boron;
		new Atom.sodium;
		new Atom.platinum;
		new Atom.fluorine;
		new Atom.vanadium]
	in
	show_list atom_list;
	let molecule_list = [
		new Molecule.water;
		new Molecule.carbon_dioxyde;
		new Molecule.dihydogen;
		new Molecule.dioxygen;
		new Molecule.benzene;
	]
	in
	show_list molecule_list
