(*
• Write a parameterized class army that has the following attributes :
◦ A member attribute of type ’a list which contains a list of instance of one of
the 3 previous classes.
◦ An add method that adds an instance ot the list (front or back).
◦ A delete method that removes the head of the list member. (front or back)
*)

class ['a] army =
	object (self)
		val _list = []
		initializer print_endline "SO MANY OF US !"
		method add (x:'a) = {<_list = _list@[x]>}
		method delete = match _list with
						| [] -> {<_list = []>}
						| _ -> {<_list = List.tl _list>}
		method battle_cry =
			print_endline "Battle cry army !";
			let rec loop_lst lst = match lst with
			| [] -> ()
			| crt::next -> print_endline (crt#to_string); loop_lst next
			in
			loop_lst _list

	end
