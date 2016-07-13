#ifndef HUMAN_A_H
# define HUMAN_A_H

# include <string>
class Weapon;

class HumanA
{
public:
	HumanA(void);
	HumanA(const std::string &s);
	HumanA(const std::string &s, Weapon &w);
	~HumanA(void);
	void			attack(void) const;
	void			setWeapon(Weapon &w);
protected:
private:
	std::string		_name;
	Weapon			*_w;
};

#endif
