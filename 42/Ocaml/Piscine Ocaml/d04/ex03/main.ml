let () =
  let rec print_list lst =
		match lst with
		| [] -> ()
		| head::tail ->
			(
				print_endline head;
				print_list tail
			)
	in
	print_list (Deck.toStringList Deck.newDeck);
	print_list (Deck.toStringListVerbose Deck.newDeck);
	let rec loop_t t =
		match t with
		| (a, b) ->
			(
				print_list (Deck.toStringList b);
				print_string (Deck.Card.Color.toString (Deck.Card.getColor a));
				print_char '-';
				print_endline (Deck.Card.Value.toString (Deck.Card.getValue a));
				print_char '-';
				print_endline (Deck.Card.toStringVerbose a);
				print_char '\n';
				loop_t (Deck.drawCard b)
			)
	in
	loop_t (Deck.drawCard Deck.newDeck);
	print_endline "Ciao"
