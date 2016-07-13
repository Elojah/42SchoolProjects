#ifndef I_HEURISTIC_H
# define I_HEURISTIC_H

# include <array>
# include "State.hpp"

class State;

class IHeuristic
{
public:
	virtual ~IHeuristic(void) {}

	virtual int								eval(State const &s) const = 0;
protected:
	typedef std::array<int, MAX_CASE>		tArray;
};

#endif
