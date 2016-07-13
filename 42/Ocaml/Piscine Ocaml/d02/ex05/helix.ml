type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | None

type nucleotide = {
	p: phosphate;
	d: deoxyribose;
	base: nucleobase;
}

type helix = nucleotide list

let nucleobase_to_string base = match base with
	| A -> "A"
	| T -> "T"
	| C -> "C"
	| G -> "G"
	| _ -> "None"

let nucleotide_to_string n =
	n.p ^ " - " ^ n.d ^ " - " ^ (nucleobase_to_string n.base)

let generate_nucleotide c =
	{
		p = "phosphate";
		d = "deoxyribose";
		base = match c with
			| 'A' -> A
			| 'T' -> T
			| 'C' -> C
			| 'G' -> G
			| _ -> None;
	}

let helix_to_string (h:helix) =
	let rec loop_h h acc = match h with
		| [] -> acc
		| crt::next -> if next <> [] then
						loop_h next (acc ^ (nucleotide_to_string crt) ^ " <=> ")
					   else
						loop_h next (acc ^ (nucleotide_to_string crt))
	in
	loop_h h ""

let generate_helix n =

	Random.self_init ();
	if n < 1 then []
	else
	let int_to_nucleobase_char r = match r with
		| 0 -> 'A'
		| 1 -> 'T'
		| 2 -> 'C'
		| 3 -> 'G'
		| _ -> '0'
	in

	let rec loop_n (acc:helix) n =
		if n = 0 then acc
		else loop_n (acc @
			[generate_nucleotide (int_to_nucleobase_char (Random.int 4))]) (n - 1)
	in
	loop_n [] n

let complementary_helix (h:helix) =
	let rec loop_h h (result:helix) = match h with
		| [] -> result
		| crt::next -> match crt.base with
		| A -> loop_h next (result @ [(generate_nucleotide 'T')])
		| T -> loop_h next (result @ [(generate_nucleotide 'A')])
		| C -> loop_h next (result @ [(generate_nucleotide 'G')])
		| G -> loop_h next (result @ [(generate_nucleotide 'C')])
		| _ -> loop_h next (result @ [(generate_nucleotide 'N')])
	in
	loop_h h []

(*  *)
let () =
	if (Array.length (Sys.argv) <> 2) then
		print_endline "Need int for argv"
	else
	(
		let h = generate_helix (int_of_string Sys.argv.(1))
		in
		(
			print_endline (helix_to_string h);
			print_endline (helix_to_string (complementary_helix h))
		)
	)
