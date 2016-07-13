type radar = float array * string

let eu_dist (a: float array) (b:float array) : float =
	let result = ref 0.0 in
	let len = (Array.length a - 1)in
	for i = 0 to len do
		result := !result +. ((a.(i) -. b.(i)) *. (a.(i) -. b.(i)))
	done;
	sqrt !result

let read_csv (line:string) : radar =
	let result_list = ref [] in
	let splitted_line = Str.split (Str.regexp "[,\t]+") line in
	let len = (List.length splitted_line) - 2 in
	for i = 0 to len do
		result_list := float_of_string (List.nth splitted_line i) :: !result_list
	done;
	(Array.of_list (List.rev !result_list),
		List.nth splitted_line ((List.length splitted_line) - 1))

let examples_of_file (filename:string) : radar list =
	let result = ref [] in
		let chan = open_in filename in
		try
			while true; do
				result := (read_csv (input_line chan)) :: !result
			done;
			[([||], "None")]
		with End_of_file -> close_in chan;
	List.rev !result

let get_n_first_list (set:'a list) (k:int) : 'b list =
	let rec loop_set set acc i = match set with
		| [] -> acc
		| (a, b)::next when i > 0 -> loop_set next (acc @ [a]) (i - 1)
		| crt -> acc
	in
	loop_set set [] k

let get_n_neighbours (set: 'a list) (value:'a) (k:int) : 'a list =
	let rec loop_set set acc radar_pos = match set with
		| [] -> acc
		| (a, b) as crt::next -> loop_set next (acc @ [(crt, eu_dist a radar_pos)]) radar_pos
	in
	let get_a (a, b) = a in
	let dist_list = loop_set set [] (get_a value) in
	let sort_dist_list = List.sort (fun (fa, fb) (sa, sb) -> int_of_float (fb -. sb)) dist_list in
	get_n_first_list sort_dist_list k


let one_nn (set: 'a list) (value:'a) : string =
	let neighbours = get_n_neighbours set value 1 in
	match neighbours with
		| (a, b)::next -> b
		| [] -> failwith "Didnt found neighbours ..."


let print_radar_list (set:radar list) =
	let print_array a =
		let len = Array.length a - 1 in
		for i = 0 to len do
			print_float a.(i); print_string ","
		done
	in
	let rec print_list result = match result with
		| [] -> ()
		| (a, b)::next -> print_array a; print_endline b; print_list next
	in
	print_list set

(*
Compile with oo str.cmxa examples_of_file.ml
*)
let () =
	if (Array.length (Sys.argv) <> 2) then
		print_endline "Usage: ./a.out filename:string"
	else
		try
			let init_set = (examples_of_file Sys.argv.(1)) in
			print_endline ( one_nn init_set ([|11.1; 10.7|], "I am the value") )
		with
		| Sys_error e -> print_endline ("Error:\t" ^ e)
		| Invalid_argument e -> print_endline ("Exception:\t" ^ e)

(* 			let neighbours = get_n_neighbours init_set (List.hd init_set) 3 in
			print_radar_list neighbours
 *)

