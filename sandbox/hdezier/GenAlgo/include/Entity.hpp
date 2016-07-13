#ifndef ENTITY_H
# define ENTITY_H

class Entity
{
public:
	Entity(void);
	Entity(size_t n);
	Entity(Entity const &rhs);
	~Entity(void);
	Entity	&operator=(Entity const &rhs);
	int		evaluate(void) const;
	void	reborn(Entity const &a, Entity const &b);
protected:
private:
	int		_a;
	int		_b;
	int		_c;
};

std::ostream	&operator<<(std::ostream &s, Entity const &rhs);

#endif
