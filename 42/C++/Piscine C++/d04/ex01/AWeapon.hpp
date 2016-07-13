#ifndef A_WEAPON_H
# define A_WEAPON_H

# include <string>

class AWeapon
{
public:
	AWeapon(std::string const & name, int apcost, int damage);
	virtual ~AWeapon(void);
	AWeapon(AWeapon const &src);
	AWeapon&	operator=(AWeapon const &rhs);

	std::string const	&getName(void) const;
	int					getAPCost(void) const;
	int					getDamage(void) const;
	virtual void		attack(void) const = 0;

protected:
	std::string			_name;
	size_t				_damages;
	size_t				_cost;

private:
	AWeapon(void);
};

#endif
