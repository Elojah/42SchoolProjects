(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Parser.mli                                         :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/20 17:45:03 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/20 18:19:53 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type coord_string = string * string
type coord_int = int * int

val print_coord_string: coord_string -> unit
val print_coord_int: coord_int -> unit

val parse_line: string -> coord_string
val parse_value: coord_string -> coord_int

val is_coord_string: coord_string -> bool
