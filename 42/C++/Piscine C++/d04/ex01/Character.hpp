#ifndef CHARACTER_H
# define CHARACTER_H

# include <string>
class AWeapon;
class Enemy;

class Character
{
public:
	Character(std::string const & name);
	~Character(void);
	Character(Character const &src);
	Character&	operator=(Character const &rhs);

	void				recoverAP(void);
	void				equip(AWeapon*);
	void				attack(Enemy*);
	std::string const	&getName(void) const;
	size_t				getAPLeft(void) const;
	AWeapon				*getWeapon(void) const;
protected:
private:
	Character(void);

	std::string		_name;
	size_t			_ap;
	AWeapon			*_weapon;
};

std::ostream&	operator<<(std::ostream& stream, Character const &s);

#endif
