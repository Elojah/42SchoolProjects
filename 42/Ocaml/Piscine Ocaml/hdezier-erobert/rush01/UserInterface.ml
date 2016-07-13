(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   UserInterface.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/27 15:51:09 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/27 19:18:39 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type t = Eat | Thunder | Bath | Kill | Pet | Save | Quit | None

let draw_button x y name =
	Graphics.set_color Graphics.black;
	Graphics.fill_rect x y 100 25;
	Graphics.set_color Graphics.white;
	Graphics.moveto (x + 30) (y + 6);
	Graphics.draw_string name

let draw_status x y percent name =
	if (percent > 50) then
		Graphics.set_color Graphics.green
	else if (percent > 25) then
		Graphics.set_color Graphics.yellow
	else
		Graphics.set_color Graphics.red;
	Graphics.fill_rect x y percent 25;
	Graphics.set_color Graphics.white;
	Graphics.fill_rect (x + percent) y (100 - percent) 25;
	Graphics.set_color Graphics.black;
	Graphics.draw_rect x y 100 25;
	Graphics.moveto (x + 30) (y + 6);
	Graphics.draw_string name

let init creature =
	Graphics.open_graph " 900x900";
	Graphics.set_font "-*-fixed-medium-r-semicondensed--12-*-*-*-*-*-iso8859-1";
	Graphics.clear_graph ();
	Graphics.moveto 425 500;
	Graphics.draw_string creature#name;
	Graphics.set_color Graphics.red;
	Graphics.moveto 400 490;
	Graphics.draw_string "        ,-.      .-,";
	Graphics.moveto 400 480;
	Graphics.draw_string "        |-.\\ __ /.-|";
	Graphics.moveto 400 470;
	Graphics.draw_string "        \\  `    `  /";
	Graphics.moveto 400 460;
	Graphics.draw_string "        / _     _  \\";
	Graphics.moveto 400 450;
	Graphics.draw_string "        | _`q  p _ |";
	Graphics.moveto 400 440;
	Graphics.draw_string "        '._=/  \\=_.'";
	Graphics.moveto 400 430;
	Graphics.draw_string "          {`\\()/`}`\\";
	Graphics.moveto 400 420;
	Graphics.draw_string "          {      }  \\";
	Graphics.moveto 400 410;
	Graphics.draw_string "          |{    }    \\";
	Graphics.moveto 400 390;
	Graphics.draw_string "          \\ '--'   .- \\";
	Graphics.moveto 400 380;
	Graphics.draw_string "          |-      /    \\";
	Graphics.moveto 400 370;
	Graphics.draw_string "          | | | | |     ;";
	Graphics.moveto 400 360;
	Graphics.draw_string "          | | |.;.,..__ |";
	Graphics.moveto 400 350;
	Graphics.draw_string "        .-'';`         `|";
	Graphics.moveto 400 340;
	Graphics.draw_string "       /    |           /";
	Graphics.moveto 400 330;
	Graphics.draw_string "       `-../____,..---'`";
	draw_button 150 125 "EAT";
	draw_button 275 125 "THUNDER";
	draw_button 400 125 "KILL";
	draw_button 525 125 "BATH";
	draw_button 650 125 "PET"

let display creature =
	draw_status 150 800 creature#health "HEALTH";
	draw_status 275 800 creature#energy "ENERGY";
	draw_status 400 800 creature#happiness "HAPPINESS";
	draw_status 525 800 creature#hygien "HYGIEN";
	draw_status 650 800 creature#cuteness "CUTENESS"

let rec getEvent () =
	let event =
		Graphics.wait_next_event [Graphics.Poll]
	in
	match event with
	| e when e.Graphics.keypressed ->
		 (
			 match (Graphics.read_key ()) with
			 | 's' -> print_endline "Save"; Save
			 | 'q' -> print_endline "Quit"; Quit
			 | _ -> None
		 )
	| e when e.Graphics.button ->
		 (
			 let x = event.Graphics.mouse_x in
			 let y = event.Graphics.mouse_y in
			 let rec release time =
				 if (Unix.gettimeofday () -. time > 0.3) then
					 (
						 if (y < 150 && y > 125 && (Graphics.button_down () = false)) then
							 match x with
							 | x when x > 150 && x < 250 -> print_endline "Eat"; Eat
							 | x when x > 275 && x < 375 -> print_endline "Thunder"; Thunder
							 | x when x > 400 && x < 500 -> print_endline "Kill"; Kill
							 | x when x > 525 && x < 625 -> print_endline "Bath"; Bath
							 | x when x > 650 && x < 750 -> print_endline "Pet"; Pet
							 | _ -> None
						 else
							 None
					 )
				 else
					 release time
			 in
			 release (Unix.gettimeofday ())
		 )
	| _ -> None
