#ifndef HAMMING_H
# define HAMMING_H

# include "IHeuristic.hpp"
class State;

class Hamming: public IHeuristic
{
public:
	Hamming(State const &s);
	virtual ~Hamming(void);

	virtual int		eval(State const &s) const;
private:
	tArray			_finalMap;
	size_t			_size;

	Hamming(void);
	Hamming(Hamming const &h);

	Hamming			&operator=(Hamming const &h);
};

#endif
