#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap(void) : ClapTrap() {
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 5;
	_armorDamageReduction = 0;
	_name = "Unnamed";
	std::cout << "\t--\tstart bootup sequence NinjaTrap style" << std::endl;
	std::srand(std::clock());
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap() {
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 5;
	_armorDamageReduction = 0;
	_name = name;
	std::cout << "\t--\tstart bootup sequence NinjaTrap style" << std::endl;
	std::srand(std::clock());
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap() {
	*this = src;
	std::cout << "\t--\tstart bootup sequence NinjaTrap style" << std::endl;
	std::srand(std::clock());
}

NinjaTrap::~NinjaTrap(void) {
	std::cout << _name << "\t--\tNo, nooo, you are so STUPID! NinjaTrap style" << std::endl;
}

void		NinjaTrap::ninjaShoebox(ClapTrap const &target)
{
	static int					r;
	static const std::string	tab[19] = {
		"01010110",
		"01001001",
		"01010110",
		"01000001",
		"00100000",
		"01001100",
		"01000001",
		"00100000",
		"01010010",
		"01001111",
		"01010010",
		"01001111",
		"01001100",
		"01010101",
		"01010100",
		"01001001",
		"01001111",
		"01001110"
	};

	(void)target;
	r = std::rand() % 18;
	std::cout << "\tNinjaTrap talking to ClapTrap!\t" << tab[r] << std::endl;
}
void		NinjaTrap::ninjaShoebox(FragTrap const &target)
{
	static int					r;
	static const std::string	tab[19] = {
		"01010110",
		"01001001",
		"01010110",
		"01000001",
		"00100000",
		"01001100",
		"01000001",
		"00100000",
		"01010010",
		"01001111",
		"01010010",
		"01001111",
		"01001100",
		"01010101",
		"01010100",
		"01001001",
		"01001111",
		"01001110"
	};

	(void)target;
	r = std::rand() % 19;
	std::cout << "\tNinjaTrap talking to FragTrap!\t" << tab[r] << std::endl;
}
void		NinjaTrap::ninjaShoebox(ScavTrap const &target)
{
	static int					r;
	static const std::string	tab[19] = {
		"01010110",
		"01001001",
		"01010110",
		"01000001",
		"00100000",
		"01001100",
		"01000001",
		"00100000",
		"01010010",
		"01001111",
		"01010010",
		"01001111",
		"01001100",
		"01010101",
		"01010100",
		"01001001",
		"01001111",
		"01001110"
	};

	(void)target;
	r = std::rand() % 19;
	std::cout << "\tNinjaTrap talking to ScavTrap!\t" << tab[r] << std::endl;
}
void		NinjaTrap::ninjaShoebox(NinjaTrap const &target)
{
	static int					r;
	static const std::string	tab[19] = {
		"01010110",
		"01001001",
		"01010110",
		"01000001",
		"00100000",
		"01001100",
		"01000001",
		"00100000",
		"01010010",
		"01001111",
		"01010010",
		"01001111",
		"01001100",
		"01010101",
		"01010100",
		"01001001",
		"01001111",
		"01001110"
	};

	(void)target;
	r = std::rand() % 19;
	std::cout << "\tNinjaTrap talking to NinjaTrap!\t" << tab[r] << std::endl;
}
