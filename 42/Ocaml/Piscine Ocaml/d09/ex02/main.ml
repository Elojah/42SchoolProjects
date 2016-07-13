let () =
	print_endline (string_of_int (Calc.Calc_int.fact 3));
	print_endline (string_of_float (Calc.Calc_float.power 3.0 3));
	print_endline (string_of_int (Calc.Calc_int.mul (Calc.Calc_int.add 20 1) 2));
	print_endline (string_of_float (Calc.Calc_float.mul (Calc.Calc_float.add 20.0 1.0) 2.0));
	print_endline (string_of_int (Calc.Calc_int.power (Calc.Calc_int.add 20 1) 2));
	print_endline (string_of_float (Calc.Calc_float.fact (Calc.Calc_float.add 2.0 1.0)));
	print_endline "See_ya !"
