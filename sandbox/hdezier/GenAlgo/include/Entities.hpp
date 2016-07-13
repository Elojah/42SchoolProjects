#ifndef ENTITIES_H
# define ENTITIES_H

# include "Entity.hpp"
class Entity;

class Entities
{
public:
	Entities(void);
	Entities(Entities const &rhs);
	~Entities(void);
	Entities	&operator=(Entities const &rhs);
protected:
private:
	size_t		_n;
	Entity		*_set;
	const size_t	melt;
};

#endif
