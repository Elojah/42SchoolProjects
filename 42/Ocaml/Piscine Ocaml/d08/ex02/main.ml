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
	let alkane_list = [
		new Alkane.methane;
		new Alkane.ethane;
		new Alkane.propane;
		new Alkane.butane;
		new Alkane.pentane;
		new Alkane.hexane;
		new Alkane.heptane;
		new Alkane.octane;
		new Alkane.nonane;
		new Alkane.decane;
		new Alkane.undecane;
		new Alkane.dodecane;
		new Alkane.hexadecane;
		new Alkane.icosane;
		new Alkane.triacontane;
		new Alkane.tetracontane;
		new Alkane.pentacontane;
		new Alkane.hexacontane;
	]
	in
	show_list alkane_list;
	let alk0 = new Alkane.methane in
	let alk1 = new Alkane.ethane in
	let alk2 = new Alkane.methane in
	print_endline (string_of_bool (alk0#equals alk2));
	print_endline (string_of_bool (alk0#equals alk1));
	print_endline (string_of_bool (alk0#equals alk0))
