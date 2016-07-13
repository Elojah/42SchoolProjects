#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) :
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(100),
	_maxEnergyPoints(100),
	_level(1),
	_meleeAttackDamage(30),
	_rangedAttackDamage(20),
	_armorDamageReduction(5),
	_name("Unnamed") {
	std::cout << "\t--\tstart bootup sequence" << std::endl;
	std::srand(std::clock());
}

FragTrap::FragTrap(std::string name) :
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(100),
	_maxEnergyPoints(100),
	_level(1),
	_meleeAttackDamage(30),
	_rangedAttackDamage(20),
	_armorDamageReduction(5),
	_name(name) {
	std::cout << _name << "\t--\tstart bootup sequence." << std::endl;
	std::srand(std::clock());
}

FragTrap::FragTrap(FragTrap const &src) {
	*this = src;
	std::cout << _name << "\t--\tstart bootup sequence." << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << _name << "\t--\tNo, nooo, you are so STUPID!"  << std::endl;
}

std::string	FragTrap::getName(void) const {return (_name);}
size_t		FragTrap::getHitPoints(void) const {return (_hitPoints);}
size_t		FragTrap::getMaxHitPoints(void) const {return (_maxHitPoints);}
size_t		FragTrap::getEnergyPoints(void) const {return (_energyPoints);}
size_t		FragTrap::getMaxEnergyPoints(void) const {return (_maxEnergyPoints);}
size_t		FragTrap::getLevel(void) const {return (_level);}
size_t		FragTrap::getMeleeAttackDamage(void) const {return (_meleeAttackDamage);}
size_t		FragTrap::getRangedAttackDamage(void) const {return (_rangedAttackDamage);}
size_t		FragTrap::getArmorDamageReduction(void) const {return (_armorDamageReduction);}

void	FragTrap::rangedAttack(std::string const & target) {
	std::cout << _name << "\tattacks\t" << target << "\twith ranged attack." << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target) {
	std::cout << _name << "\tattacks\t" << target << "\twith melee attack." << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	if (amount > _armorDamageReduction) {
		if (amount - _armorDamageReduction > _hitPoints) {
			_hitPoints = 0;
			std::cout << _name << "\ttook\t" << amount - _armorDamageReduction << "\tdamages." << std::endl;
			std::cout << "\t--\tI'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
		} else {
			_hitPoints -= (amount - _armorDamageReduction);
			std::cout << _name << "\ttook\t" << amount - _armorDamageReduction << "\tdamages." << std::endl;
		}
	} else {
		std::cout << _name << "\tarmor absorbed damages." << std::endl;
	}
	std::cout << "\t\t" << _hitPoints << "\tleft." << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (amount + _hitPoints > _maxHitPoints) {
		_hitPoints = _maxHitPoints;
	} else {
		_hitPoints += amount;
	}
	std::cout << _name << "\thas been repaired for\t" << amount << "\thp." << std::endl;
	std::cout << "\t\t" << _hitPoints << "\tleft." << std::endl;
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


FragTrap		&FragTrap::operator=(FragTrap const &rhs) {
	if (this != &rhs) {
		_hitPoints = rhs.getHitPoints();
		_maxHitPoints = rhs.getMaxHitPoints();
		_energyPoints = rhs.getEnergyPoints();
		_maxEnergyPoints = rhs.getMaxEnergyPoints();
		_level = rhs.getLevel();
		_meleeAttackDamage = rhs.getMeleeAttackDamage();
		_rangedAttackDamage = rhs.getRangedAttackDamage();
		_armorDamageReduction = rhs.getArmorDamageReduction();
		_name = rhs.getName();
	}
	return (*this);
}
