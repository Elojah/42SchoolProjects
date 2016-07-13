let jokes_array i = match i with
	| 0 -> "I've lost almost ten pounds now. You see what I mean? I totally know what it's like to be a Jew in the Holocaust now."
	| 1 -> "I want to get down on my knees and start pleasing Jesus. I want to feel his salvation all over my face."
	| 2 -> "You guys hear how poor Cartman's mom is?! His mom is so poor the ducks throw bread at her!"
	| 3 -> "Oh heell no, my momma's so poor she opend a GMail account just so she could eat the spam!"
	| 4 -> "Cartman's mom is so poor that when she goes to KFC, she has to lick other people's fingers!"
	| 5 -> "Awwww my mom is so poor she walked down the road with one shoooe. [backs up] And if you ask her if she lost a shoe, she'd say 'No I found ooone.'"
	| _ -> "No jokes :("

let () =
	Random.self_init ();
	let size = 5 in
	let my_jokes_array = Array.init size jokes_array in
	print_endline (Array.get my_jokes_array (Random.int size))
