#ifndef MAX_SWAP_H
# define MAX_SWAP_H

# include "IHeuristic.hpp"
class State;

class MaxSwap: public IHeuristic
{
public:
	MaxSwap(State const &s);
	virtual ~MaxSwap(void);

	virtual int		eval(State const &s) const;
private:
	tArray			_finalMap;
	size_t			_size;

	MaxSwap(void);
	MaxSwap(MaxSwap const &mS);

	MaxSwap			&operator=(MaxSwap const &mS);
};

#endif
