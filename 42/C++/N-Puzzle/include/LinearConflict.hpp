#ifndef LINEAR_CONFLICT_H
# define LINEAR_CONFLICT_H

# include "IHeuristic.hpp"
class State;

class LinearConflict: public IHeuristic
{
public:
	LinearConflict(State const &s);
	virtual ~LinearConflict(void);

	virtual int		eval(State const &s) const;
private:
	tArray			_finalMap;
	size_t			_size;

	LinearConflict(void);
	LinearConflict(LinearConflict const &lC);

	LinearConflict	*operator=(LinearConflict const &lC);

	int				isInLine(int line, int n) const;
	int				isInColumn(int col, int n) const;
};

#endif
