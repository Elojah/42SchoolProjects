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
