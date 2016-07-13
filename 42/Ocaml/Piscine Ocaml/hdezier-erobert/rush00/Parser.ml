(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Parser.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/20 17:52:40 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/21 18:37:56 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type coord_string = (string * string)
type coord_int = (int * int)
					 
let print_coord_string coord =
	match coord with
	| (first, second) -> Printf.printf "(%s %s)" first second

let print_coord_int coord =
	match coord with
	| (first, second) -> Printf.printf "(%i %i)" first second

let parse_line line =
	let len = String.length line in
	let rec tok_space line i =
		if (i = len) then
			len
		else if (line.[i] = ' ') then
			i
		else
			tok_space line (i + 1)
	in
	let k = (tok_space line 0) in
	if (k = len) then
		("", "")
	else
		(String.sub line 0 k, String.sub line (k + 1) (len - k - 1))
		  
let parse_value coord =
	match coord with
	| (first, second) ->
		 let x = (int_of_string first) - 1
		 and y = (int_of_string second) - 1
		 in
		 (((x / 3) + 3 * (y / 3)), ((x mod 3) + 3 * (y mod 3)))
		 
let str_digit str =
	let rec inner str i =
		if (i < String.length str) then
			if (str.[i] >= '0' && str.[i] <= '9') then
				inner str (i + 1)
			else
				false
		else
			true
	in
	if (String.length str = 0) then
	  false
	else
		inner str 0
			
let is_coord_string coord =
	match coord with
	| (first, second) ->
		 str_digit first && str_digit second
		 && int_of_string first > 0 && int_of_string first < 10
		 && int_of_string second > 0 && int_of_string second < 10
