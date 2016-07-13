type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | None

type nucleotide = {
	p: phosphate;
	d: deoxyribose;
	base: nucleobase;
}

let nucleobase_to_string base = match base with
	| A -> "A"
	| T -> "T"
	| C -> "C"
	| G -> "G"
	| _ -> "None"

let generate_nucleotide c =
	{
		p = "phosphate";
		d = "deoxyribose";
		base = match c with
			| 'A' -> A
			| 'T' -> T
			| 'C' -> C
			| 'G' -> G
			| _ -> None
	}

(*  *)
let () =
	let print_nucleotide n =
	(
		print_endline n.p;
		print_endline n.d;
		print_endline (nucleobase_to_string n.base);
	)
	in
	print_nucleotide (generate_nucleotide 'T')
