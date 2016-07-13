(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   UserInterface.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/21 19:31:08 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/21 20:43:58 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type t = X | O | None

let rec getCoord () =
	let event =
		Graphics.wait_next_event [Graphics.Button_down; Graphics.Key_pressed]
	in
	if (event.Graphics.button) then
		let x = event.Graphics.mouse_x / 100 in
		let y = event.Graphics.mouse_y / 100 in
		print_int x;
		print_char '-';
		print_int y;
		print_char '\n';
		(((x / 3) + 3 * (y / 3)), ((x mod 3) + 3 * (y mod 3)))
	else if (event.Graphics.keypressed) then
		(-1, -1)
	else
		getCoord ()

let draw_cell i j t =
	if (t = X) then
		Graphics.set_color Graphics.green
	else if (t = O) then
		Graphics.set_color Graphics.red
	else
		Graphics.set_color Graphics.white;
	let x = (i mod 3) * 3 + (j mod 3) in
	let y = (i / 3) * 3 + (j / 3) in
	Graphics.fill_rect (x * 100) (y * 100) 100 100

let rec draw_case tC i j t =
	match tC with
	| [] ->
		 ()
	| current::next when t = X ->
		 (
			 draw_cell i j X;
			 draw_case next i (j + 1) t
		 )
	| current::next when t = O ->
		 (
			 draw_cell i j O;
			 draw_case next i (j + 1) t
		 )
	| 1::next ->
		 (
			 draw_cell i j X;
			 draw_case next i (j + 1) t
		 )
	| 2::next ->
		 (
			 draw_cell i j O;
			 draw_case next i (j + 1) t
		 )
	| _::next ->
		 draw_cell i j None;
		 draw_case next i (j + 1) t

let display b =
	let rec inner b i =
		match b with
		| [] -> ()
		| current::next when TicTac.getValue current 0 = 10 ->
			 (
				 draw_case current i 0 X;
				 inner next (i + 1)
			 )
		| current::next when TicTac.getValue current 0 = 11 ->
			 (
				 draw_case current i 0 O;
				 inner next (i + 1)
			 )
		| current::next ->
			 (
				 draw_case current i 0 None;
				 inner next (i + 1)
			 )
	in
	inner b 0;
	Graphics.set_color Graphics.black;
	Graphics.moveto 300 0;
	Graphics.lineto 300 900;
	Graphics.moveto 600 0;
	Graphics.lineto 600 900;
	Graphics.moveto 0 300;
	Graphics.lineto 900 300;
	Graphics.moveto 0 600;
	Graphics.lineto 900 600


let init =
	Graphics.open_graph " 900x900";
	Graphics.clear_graph ()
