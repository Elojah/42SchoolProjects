(*
Basically, you can instantiate a new chemical reaction with a list of molecules. Then
you can call a get_result method to get the result.
All that explanation was good, but now let’s talk about code! You will write a virtual
class named reaction, which will be instantiated with two collections of molecules, one
for the start and one for the end of your reaction.
Your class will also provide the following virtual methods:
• get_start: (molecule * int) list
• get_result: (molecule * int) list
• balance: reaction
• is_balanced: bool
*)

class virtual reaction (start_list:(Molecule.molecule * int) list)
						(end_list:(Molecule.molecule * int) list) =
	object (self)
		method virtual get_start : (Molecule.molecule * int) list
		method virtual get_result : (Molecule.molecule * int) list
		method virtual balance : reaction
		method virtual is_balanced : bool
	end
