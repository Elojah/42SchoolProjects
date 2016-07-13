(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/21 18:49:10 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/21 22:54:05 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec getPlayer n =
	Printf.printf "Player %c name:\n" n;
	let result = read_line () in
	if (result = "") then
		(
			print_endline "Can't have an empty name";
			getPlayer n
		)
	else
		result

let () =
	let display =
		if (Array.length (Sys.argv) <> 1) then
			true
		else
			(
				Graphics.close_graph ();
				false
			)
	in
  let rec getNames p1 p2 =
		if (p1 <> p2) then
			Board.gameLoop Board.newBoard p1 p2 display
		else
			(
				print_endline "\nCan't have same player's names";
				getNames (getPlayer 'X') (getPlayer 'O')
			)
  in
  let rec gameRestart s =
		if s.[0] = 'y' then
			(
				getNames (getPlayer 'X') (getPlayer 'O');
				print_endline "Do you want to play again ? [y/n]";
				let s = read_line () in
				if (String.length s > 0) then
					gameRestart s;
			)
  in
  gameRestart "y";
	print_endline "Ciao"
