class virtual alkane (n:int) =
	let arkane_to_molecule (n_a:int) =
		let rec loop_n n acc = match n with
			| 0 -> acc
			| _ -> loop_n (n - 1) (acc @ [new Atom.carbon; new Atom.hydrogen; new Atom.hydrogen;])
		in
		loop_n n_a [new Atom.hydrogen; new Atom.hydrogen;]
	in
	let alkane_name (n:int) = match n with
		| 1 -> "Methane"
		| 2 -> "Ethane"
		| 3 -> "Propane"
		| 4 -> "Butane"
		| 5 -> "Pentane"
		| 6 -> "Hexane"
		| 7 -> "Heptane"
		| 8 -> "Octane"
		| 9 -> "Nonane"
		| 10 -> "Decane"
		| 11 -> "Undecane"
		| 12 -> "Dodecane"
		| 16 -> "Hexadecane"
		| 20 -> "Icosane"
		| 30 -> "Triacontane"
		| 40 -> "Tetracontane"
		| 50 -> "Pentacontane"
		| 60 -> "Hexacontane"
		| _ -> "Unrecognized"
	in
	object (self) inherit Molecule.molecule (alkane_name n, arkane_to_molecule n)
		method equals (a:alkane) : bool = self#formula = a#formula
	end

class methane =
	object (self) inherit alkane 1
	end
class ethane =
	object (self) inherit alkane 2
	end
class propane =
	object (self) inherit alkane 3
	end
class butane =
	object (self) inherit alkane 4
	end
class pentane =
	object (self) inherit alkane 5
	end
class hexane =
	object (self) inherit alkane 6
	end
class heptane =
	object (self) inherit alkane 7
	end
class octane =
	object (self) inherit alkane 8
	end
class nonane =
	object (self) inherit alkane 9
	end
class decane =
	object (self) inherit alkane 10
	end
class undecane =
	object (self) inherit alkane 11
	end
class dodecane =
	object (self) inherit alkane 12
	end
class hexadecane =
	object (self) inherit alkane 16
	end
class icosane =
	object (self) inherit alkane 20
	end
class triacontane =
	object (self) inherit alkane 30
	end
class tetracontane =
	object (self) inherit alkane 40
	end
class pentacontane =
	object (self) inherit alkane 50
	end
class hexacontane =
	object (self) inherit alkane 60
	end

