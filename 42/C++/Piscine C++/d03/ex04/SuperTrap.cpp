#include "SuperTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap(void) :
	ClapTrap(),
	NinjaTrap(),
	FragTrap() {
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	_name = "Unnamed";
	std::cout << "\t--\tstart bootup sequence SuperTrap style" << std::endl;
	std::srand(std::clock());
}

SuperTrap::SuperTrap(std::string name) :
	ClapTrap(),
	NinjaTrap(),
	FragTrap() {
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	_name = name;
	std::cout << "\t--\tstart bootup sequence SuperTrap style" << std::endl;
	std::srand(std::clock());
}

SuperTrap::SuperTrap(SuperTrap const &src) :
	ClapTrap(),
	NinjaTrap(),
	FragTrap() {
	*this = src;
	std::cout << "\t--\tstart bootup sequence SuperTrap style" << std::endl;
	std::srand(std::clock());
}

SuperTrap::~SuperTrap(void) {
	std::cout << _name << "\t--\tNo, nooo, you are so STUPID! SuperTrap style"  << std::endl;
}
