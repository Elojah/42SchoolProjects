#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap() {
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_level = 1;
	_meleeAttackDamage = 20;
	_rangedAttackDamage = 15;
	_armorDamageReduction = 3;
	_name = "Unnamed";
	std::cout << "\t--\tstart bootup sequence ScavTrap style" << std::endl;
	std::srand(std::clock());
}

ScavTrap::ScavTrap(std::string name) : ClapTrap() {
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_level = 1;
	_meleeAttackDamage = 20;
	_rangedAttackDamage = 15;
	_armorDamageReduction = 3;
	_name = name;
	std::cout << "\t--\tstart bootup sequence ScavTrap style" << std::endl;
	std::srand(std::clock());
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap() {
	*this = src;
	std::cout << "\t--\tstart bootup sequence ScavTrap style" << std::endl;
	std::srand(std::clock());
}

ScavTrap::~ScavTrap(void) {
	std::cout << _name << "\t--\tNo, nooo, you are so STUPID! ScavTrap style"  << std::endl;
}

void		ScavTrap::challengeNewcomer(void) {
	static int					r;
	static const std::string	tab[3] = {
		"Can you jump?",
		"Can you run?",
		"Can you die?"
	};

	r = std::rand() % 3;
	std::cout << "\tNew challenge !\t" << tab[r] << std::endl;
}
