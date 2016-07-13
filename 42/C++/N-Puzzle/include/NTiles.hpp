#ifndef N_TILES_H
# define N_TILES_H

# include "IHeuristic.hpp"
class State;

class NTiles: public IHeuristic
{
public:
	NTiles(State const &s);
	virtual ~NTiles(void);

	virtual int		eval(State const &s) const;
private:
	tArray			_finalMap;
	size_t			_size;

	NTiles(void);
	NTiles(NTiles const &nT);

	NTiles			&operator=(NTiles const &nT);
};

#endif
