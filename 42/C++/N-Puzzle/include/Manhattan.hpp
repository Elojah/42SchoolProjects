#ifndef MANHATTAN_H
# define MANHATTAN_H

# define DIST(a, b) (((a) > (b)) ? (a) - (b) : (b) - (a))

# include "IHeuristic.hpp"
class State;

class Manhattan: public IHeuristic
{
public:
	Manhattan(State const &s);
	~Manhattan(void);

	virtual int		eval(State const &s) const;
private:
	tArray			_finalMap;
	size_t			_size;

	Manhattan(void);
	Manhattan(Manhattan const &m);

	Manhattan		&operator=(Manhattan const &m);
};

#endif
