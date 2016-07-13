(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   UserInterface.mli                                  :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/27 15:48:21 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/27 16:20:52 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type t = Eat | Thunder | Bath | Kill | Pet | Save | Quit | None

val init: Creature.creature -> unit
val display: Creature.creature -> unit
val getEvent: unit -> t
