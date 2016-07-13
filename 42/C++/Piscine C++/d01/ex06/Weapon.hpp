#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class Weapon
{
public:
						Weapon(void);
						Weapon(const std::string &s);
						~Weapon(void);
	void				setType(const std::string &s);
	const std::string	&getType(void);
protected:
private:
	std::string			_type;
};

#endif
