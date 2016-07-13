#ifndef HUMAN_B_H
# define HUMAN_B_H

# include <string>
class Weapon;

class HumanB
{
public:
	HumanB(void);
	HumanB(const std::string &s);
	HumanB(const std::string &s, Weapon &w);
	~HumanB(void);
	void			attack(void) const;
	void			setWeapon(Weapon &w);
protected:
private:
	std::string		_name;
	Weapon			*_w;
};

#endif
