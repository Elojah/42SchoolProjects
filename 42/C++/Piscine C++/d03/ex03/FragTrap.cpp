#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap() {
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_maxEnergyPoints = 100;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	_name = "Unnamed";
	std::cout << "\t--\tstart bootup sequence FragTrap style" << std::endl;
	std::srand(std::clock());
}

FragTrap::FragTrap(std::string name) : ClapTrap() {
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_maxEnergyPoints = 100;
	_level = 1;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	_name = name;
	std::cout << "\t--\tstart bootup sequence FragTrap style" << std::endl;
	std::srand(std::clock());
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap() {
	*this = src;
	std::cout << "\t--\tstart bootup sequence FragTrap style" << std::endl;
	std::srand(std::clock());
}

FragTrap::~FragTrap(void) {
	std::cout << _name << "\t--\tNo, nooo, you are so STUPID! FragTrap style"  << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {
	static int			r;
	static const sAtk	tab[5] = {
		{
			"Protect humanity!",
			&FragTrap::rangedAttack
		},
		{
			"Dance!",
			&FragTrap::rangedAttack
		},
		{
			"Let me know if you have any other portal-rific needs!",
			&FragTrap::meleeAttack
		},
		{
			"Demoted back to door-opening servitude!",
			&FragTrap::rangedAttack
		},
		{
			"I can do more than open doors sir!",
			&FragTrap::meleeAttack
		}
	};

	if (_energyPoints < 25) {
		std::cout << "\tNo more energy points for vaulthunter_dot_exe..." << std::endl;
		return ;
	}
	_energyPoints -= 25;
	r = std::rand() % 5;
	std::cout << "\tvaulthunter_dot_exe launched." << std::endl;
	std::cout << tab[r].display << std::endl;
	(this->*(tab[r].attack))(target);
}
