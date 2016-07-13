let rec show_list lst = match lst with
	| [] -> ()
	| crt::next -> print_endline crt#to_string; show_list next

let () =
	let atom_list = [
		new Atom.hydrogen;
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
	show_list molecule_list;
	print_endline "_____________________";
	let alkane_list = [
		(* new Alkane.methane; *)
		new Alkane.ethane;
		new Alkane.propane;
		new Alkane.butane;
		new Alkane.pentane;
		new Alkane.hexane;
		new Alkane.heptane;
		new Alkane.octane;
		(* new Alkane.nonane; *)
		(* new Alkane.decane; *)
		(* new Alkane.undecane; *)
		(* new Alkane.dodecane; *)
		(* new Alkane.hexadecane; *)
		(* new Alkane.icosane; *)
		(* new Alkane.triacontane; *)
		(* new Alkane.tetracontane; *)
		(* new Alkane.pentacontane; *)
		(* new Alkane.hexacontane; *)
	]
	in
	show_list alkane_list;
	print_endline "_____________________";
	let comb = new Reaction.alkane_combustion alkane_list in
	let b_comb = if (comb#is_balanced) then comb else (print_endline "Let's balance this !";comb#balance)
	in
	print_endline (string_of_bool b_comb#is_balanced);
	print_endline b_comb#to_string


