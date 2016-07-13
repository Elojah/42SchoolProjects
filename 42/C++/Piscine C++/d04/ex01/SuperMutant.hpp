#ifndef SUPER_MUTANT_H
# define SUPER_MUTANT_H

# include "Enemy.hpp"
class Enemy;

class SuperMutant : public Enemy
{
public:
	SuperMutant(void);
	virtual ~SuperMutant(void);
	SuperMutant(SuperMutant const &src);
	SuperMutant&	operator=(SuperMutant const &rhs);
	virtual void		takeDamage(int);
protected:
private:
};

#endif
