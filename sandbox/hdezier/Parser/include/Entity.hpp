#ifndef ENTITY_H
# define ENTITY_H

# include "IToken.hpp"

class Entity : public IToken
{
public:
	Entity(void);
	~Entity(void);
	int				detect(const char &c);
	int				getPriority(void) const;
protected:
private:
};

#endif
