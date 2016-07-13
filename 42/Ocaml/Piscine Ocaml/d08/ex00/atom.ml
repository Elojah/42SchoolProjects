(*
You will write a virtual class named atom for...an atom. Today we’re doing some
chemistry! An atom is defined by a few things:
• A name, of type string.
• A symbol, of type string.
• An atomic_number, of type int.
All these things have to be methods, and you have to be able to set what they return
through the atom’s constructor. Of course, feel free to look up what an atom is if you
don’t understand what these are.
Your class will contain at least a to_string method to describe shortly what your
atom is, and an equals method to compare atoms; aside from that, you can implement
anything you think is suitable or you may need in the next exercises.
To go along with your atom virtual class, you will also write some real atoms, which
will of course inherit your atom class. You have to write at least the following classes:
• hydrogen
• carbon
• oxygen
• And three more atoms of your choice, as long as they really exist.
*)

class virtual atom (param : string * string * int) =
	object (self)
		val _info = param

		method name = match _info with (m_name, _, _) -> m_name
		method symbol = match _info with (_, m_symbol, _) -> m_symbol
		method atomic_number = match _info with (_, _, m_atomic_number) -> m_atomic_number

		method to_string = match _info with (m_name, m_symbol, m_atomic_number) ->
							m_name ^ ":" ^ m_symbol ^ "->" ^ string_of_int m_atomic_number
	end

class hydrogen =
	object (self) inherit atom ("Hydrogen", "H", 1)
	end

class carbon =
	object (self) inherit atom ("Carbon", "C", 6)
	end

class oxygen =
	object (self) inherit atom ("Oxygen", "O", 8)
	end

class boron =
	object (self) inherit atom ("Boron", "B", 5)
	end

class sodium =
	object (self) inherit atom ("Sodium", "Na", 11)
	end

class platinum =
	object (self) inherit atom ("Platinum", "Pt", 78)
	end

class fluorine =
	object (self) inherit atom ("Fluorine", "F", 9)
	end

class vanadium =
	object (self) inherit atom ("Vanadium", "V", 23)
	end
