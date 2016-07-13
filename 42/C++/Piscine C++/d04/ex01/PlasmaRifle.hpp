#ifndef PLASMA_RIFLE_H
# define PLASMA_RIFLE_H

# include "AWeapon.hpp"
class AWeapon;

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle(void);
	~PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const &src);
	PlasmaRifle&	operator=(PlasmaRifle const &rhs);
	virtual void		attack(void) const;
protected:
private:
};

#endif
