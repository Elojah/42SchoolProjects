type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | U | None

type nucleotide = {
	p: phosphate;
	d: deoxyribose;
	base: nucleobase;
}

type helix = nucleotide list
type rna = nucleobase list
type aminoacid = Stop | Ala | Arg | Asn | Asp | Cys | Gln | Glu | Gly | His | Ile | Leu | Lys | Met | Phe | Pro | Ser | Thr | Trp | Tyr | Val
type protein = {
	a: aminoacid list;
	to_string: protein->string;
}

let nucleobase_to_string base = match base with
	| A -> "A"
	| T -> "T"
	| C -> "C"
	| G -> "G"
	| U -> "U"
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
			| 'U' -> U
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
		| 4 -> 'U'
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

let rna_to_string (r:rna) =
	let rec loop_r r acc = match r with
		| [] -> acc
		| crt::next -> if next <> [] then
						loop_r next (acc ^ (nucleobase_to_string crt) ^ " <=> ")
					   else
						loop_r next (acc ^ (nucleobase_to_string crt))
	in
	loop_r r ""

let generate_rna (h:helix) =
	let rec loop_h h (result:rna) = match h with
		| [] -> result
		| crt::next -> match crt.base with
		| A -> loop_h next (result @ [U])
		| T -> loop_h next (result @ [A])
		| C -> loop_h next (result @ [G])
		| G -> loop_h next (result @ [C])
		| _ -> loop_h next (result @ [None])
	in
	loop_h h []

let triplets_to_string t =
	let get_a (a, b, c) = a
	and get_b (a, b, c) = b
	and get_c (a, b, c) = c
	in
	let rec loop_t t acc = match t with
		| [] -> acc
		| crt::next -> if next <> [] then loop_t next (acc ^
										(nucleobase_to_string (get_a crt)) ^
										(nucleobase_to_string (get_b crt)) ^
										(nucleobase_to_string (get_c crt)) ^
										" - ")
					   else loop_t next (acc ^
										(nucleobase_to_string (get_a crt)) ^
										(nucleobase_to_string (get_b crt)) ^
										(nucleobase_to_string (get_c crt)))
	in
	loop_t t ""

let generate_bases_triplets (r:rna) =
	let rec loop_r_3 (r:rna) acc first second n = match r with
		| [] -> acc
		| crt::next -> if n = 0 then loop_r_3 next (acc @ [(first, second, crt)]) first second 2
				   else if n = 1 then loop_r_3 next acc first crt 0
				   else if n = 2 then loop_r_3 next acc crt second 1
				   else acc
	in
	loop_r_3 r [] A A 2


(*
∗ UAA, UAG, UGA : End of translation -> Stop
∗ GCA, GCC, GCG, GCU : Alanine -> Ala
∗ AGA, AGG, CGA, CGC, CGG, CGU : Arginine -> Arg
∗ AAC, AAU : Asparagine -> Asn
∗ GAC, GAU : Aspartique -> Asp
∗ UGC, UGU : Cysteine -> Cys
∗ CAA, CAG : Glutamine -> Gln
∗ GAA, GAG : Glutamique -> Glu
∗ GGA, GGC, GGG, GGU : Glycine -> Gly
∗ CAC, CAU : Histidine -> His
∗ AUA, AUC, AUU : Isoleucine -> Ile
∗ CUA, CUC, CUG, CUU, UUA, UUG : Leucine -> Leu
∗ AAA, AAG : Lysine -> Lys
∗ AUG : Methionine -> Met
∗ UUC, UUU : Phenylalanine -> Phe
∗ CCC, CCA, CCG, CCU : Proline -> Pro
∗ UCA, UCC, UCG, UCU, AGU, AGC : Serine -> Ser
∗ ACA, ACC, ACG, ACU : Threonine -> Thr
∗ UGG : Tryptophane -> Trp
∗ UAC, UAU : Tyrosine -> Tyr
∗ GUA, GUC, GUG, GUU : Valine -> Val
*)

let decode_arn (r:rna) =
	let rec loop_r r acc = match r with
		| [] -> acc
		| (A, U, G)::next -> loop_r next (acc @ [Met])
		| (U, G, G)::next -> loop_r next (acc @ [Trp])
		| (A, A, U)::(A, A, C)::next -> loop_r next (acc @ [Asn])
		| (G, A, U)::(G, A, C)::next -> loop_r next (acc @ [Asp])
		| (U, G, U)::(U, G, C)::next -> loop_r next (acc @ [Cys])
		| (C, A, G)::(C, A, A)::next -> loop_r next (acc @ [Gln])
		| (G, A, G)::(G, A, A)::next -> loop_r next (acc @ [Glu])
		| (C, A, U)::(C, A, C)::next -> loop_r next (acc @ [His])
		| (A, A, G)::(A, A, A)::next -> loop_r next (acc @ [Lys])
		| (U, U, U)::(U, U, C)::next -> loop_r next (acc @ [Phe])
		| (U, A, U)::(U, A, C)::next -> loop_r next (acc @ [Tyr])
		| (U, G, A)::(U, A, A)::(U, A, G)::next -> loop_r next (acc @ [Stop])
		| (A, U, U)::(A, U, A)::(A, U, C)::next -> loop_r next (acc @ [Ile])
		| (G, C, U)::(G, C, A)::(G, C, C)::(G, C, G)::next -> loop_r next (acc @ [Ala])
		| (G, G, U)::(G, G, A)::(G, G, C)::(G, G, G)::next -> loop_r next (acc @ [Gly])
		| (C, C, U)::(C, C, C)::(C, C, A)::(C, C, G)::next -> loop_r next (acc @ [Pro])
		| (G, U, U)::(G, U, A)::(G, U, C)::(G, U, G)::next -> loop_r next (acc @ [Val])
		| (A, C, U)::(A, C, A)::(A, C, C)::(A, C, G)::next -> loop_r next (acc @ [Thr])
		| (U, U, G)::(C, U, A)::(C, U, C)::(C, U, G)::(C, U, U)::(U, U, A)::next -> loop_r next (acc @ [Leu])
		| (C, G, U)::(A, G, A)::(A, G, G)::(C, G, A)::(C, G, C)::(C, G, G)::next -> loop_r next (acc @ [Arg])
		| (A, G, C)::(U, C, A)::(U, C, C)::(U, C, G)::(U, C, U)::(A, G, U)::next -> loop_r next (acc @ [Ser])
		| (_, _, _)::next -> loop_r next acc
	and protein_to_string (p:protein) =
		let rec loop_p lst acc = match lst with
			| [] -> acc
			| Stop::next -> "End of translation"
			| Ala::next -> loop_p next (acc ^ " Alanine ")
			| Arg::next -> loop_p next (acc ^ " Arginine ")
			| Asp::next -> loop_p next (acc ^ " Asparagine ")
			| Cys::next -> loop_p next (acc ^ " Cysteine ")
			| Glu::next -> loop_p next (acc ^ " Glutamine ")
			| Gly::next -> loop_p next (acc ^ " Glycine ")
			| His::next -> loop_p next (acc ^ " Histidine ")
			| Ile::next -> loop_p next (acc ^ " Isoleucine ")
			| Leu::next -> loop_p next (acc ^ " Leucine ")
			| Lys::next -> loop_p next (acc ^ " Lysine ")
			| Met::next -> loop_p next (acc ^ " Methionine ")
			| Phe::next -> loop_p next (acc ^ " Phenylalanine ")
			| Pro::next -> loop_p next (acc ^ " Proline ")
			| Ser::next -> loop_p next (acc ^ " Serine ")
			| Thr::next -> loop_p next (acc ^ " Threonine ")
			| Trp::next -> loop_p next (acc ^ " Tryptophane ")
			| Tyr::next -> loop_p next (acc ^ " Tyrosine ")
			| Val::next -> loop_p next (acc ^ " Valine ")
			| _::next -> loop_p next (acc ^ "Unrecognized aminoacid")
		in
		loop_p p.a ""
	in
	{
		a = loop_r (generate_bases_triplets r) [];
		to_string = protein_to_string;
	}

let generate_helix_str n str =

	if n < 1 then []
	else
	let rec loop_n (acc:helix) n =
		if n = 0 then acc
		else loop_n (acc @
			[generate_nucleotide (str.[n - 1])]) (n - 1)
	in
	loop_n [] n

(*  *)
let () =
	if (Array.length (Sys.argv) <> 3) then
		print_endline "Need int for argv"
	else
	(
		let h = generate_helix_str (int_of_string Sys.argv.(1)) Sys.argv.(2)
		in
		(
			print_endline "Original helix ________________________";
			print_endline (helix_to_string h);
			print_endline "Complementary helix ________________________";
			print_endline (helix_to_string (complementary_helix h));
			print_endline "RNA helix ________________________";
			print_endline (rna_to_string (generate_rna h));
			print_endline "Triplets helix ________________________";
			print_endline (triplets_to_string (generate_bases_triplets (generate_rna h)));
			print_endline "Protein helix ________________________";
			let protein = decode_arn (generate_rna h)
			in
			print_endline (protein.to_string protein)
		);
	)

