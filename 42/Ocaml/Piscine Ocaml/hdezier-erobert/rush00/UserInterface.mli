(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   UserInterface.mli                                  :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/21 21:08:26 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/21 21:11:18 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

val getCoord: unit -> Parser.coord_int

val init: unit

val display: Board.t -> unit