#ifndef RAD_SCORPION_H
# define RAD_SCORPION_H

# include "Enemy.hpp"
class Enemy;

class RadScorpion : public Enemy
{
public:
	RadScorpion(void);
	virtual ~RadScorpion(void);
	RadScorpion(RadScorpion const &src);
	RadScorpion&	operator=(RadScorpion const &rhs);
	virtual void		takeDamage(int);
protected:
private:
};

#endif
