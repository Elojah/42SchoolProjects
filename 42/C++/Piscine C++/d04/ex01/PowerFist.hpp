#ifndef POWER_FIST_H
# define POWER_FIST_H

# include "AWeapon.hpp"
class AWeapon;

class PowerFist : public AWeapon
{
public:
	PowerFist(void);
	~PowerFist(void);
	PowerFist(PowerFist const &src);
	PowerFist&	operator=(PowerFist const &rhs);
	virtual void		attack(void) const;
protected:
private:
};

#endif
