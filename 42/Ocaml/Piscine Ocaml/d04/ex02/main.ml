let () =
	print_endline (Card.toString (Card.best Card.all));
	print_endline (Card.toStringVerbose (Card.best Card.allClubs));
	if (Card.isOf (Card.best Card.all) Card.Color.Spade) then
		print_endline "Nice"
	else
		print_endline "...";
	if (Card.isClub (Card.best Card.all)) then
		print_endline "Nice"
	else
		print_endline "...";
	print_endline (Card.toStringVerbose
		(Card.min (Card.newCard Card.Value.T2 Card.Color.Spade)
		(Card.newCard Card.Value.As Card.Color.Spade)));
	print_endline (Card.toString (Card.best []))
