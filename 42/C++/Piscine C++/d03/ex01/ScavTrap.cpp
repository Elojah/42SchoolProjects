#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) :
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(50),
	_maxEnergyPoints(50),
	_level(1),
	_meleeAttackDamage(20),
	_rangedAttackDamage(15),
	_armorDamageReduction(3),
	_name("Unnamed") {
	std::cout << "\t--\tstart bootup sequence ScavTrap style" << std::endl;
	std::srand(std::clock());
}

ScavTrap::ScavTrap(std::string name) :
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(50),
	_maxEnergyPoints(50),
	_level(1),
	_meleeAttackDamage(20),
	_rangedAttackDamage(15),
	_armorDamageReduction(3),
	_name(name) {
	std::cout << "\t--\tstart bootup sequence ScavTrap style" << std::endl;
	std::srand(std::clock());
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	*this = src;
	std::cout << "\t--\tstart bootup sequence ScavTrap style" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << _name << "\t--\tNo, nooo, you are so STUPID! ScavTrap style"  << std::endl;
}

std::string	ScavTrap::getName(void) const {return (_name);}
size_t		ScavTrap::getHitPoints(void) const {return (_hitPoints);}
size_t		ScavTrap::getMaxHitPoints(void) const {return (_maxHitPoints);}
size_t		ScavTrap::getEnergyPoints(void) const {return (_energyPoints);}
size_t		ScavTrap::getMaxEnergyPoints(void) const {return (_maxEnergyPoints);}
size_t		ScavTrap::getLevel(void) const {return (_level);}
size_t		ScavTrap::getMeleeAttackDamage(void) const {return (_meleeAttackDamage);}
size_t		ScavTrap::getRangedAttackDamage(void) const {return (_rangedAttackDamage);}
size_t		ScavTrap::getArmorDamageReduction(void) const {return (_armorDamageReduction);}

void	ScavTrap::rangedAttack(std::string const & target) {
	std::cout << _name << "\tattacks\t" << target << "\twith ranged attack.ScavTrap style" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target) {
	std::cout << _name << "\tattacks\t" << target << "\twith melee attack.ScavTrap style" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (amount > _armorDamageReduction) {
		if (amount - _armorDamageReduction > _hitPoints) {
			_hitPoints = 0;
			std::cout << _name << "\ttook\t" << amount - _armorDamageReduction << "\tdamages.ScavTrap style" << std::endl;
			std::cout << "\t--\tI'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
		} else {
			_hitPoints -= (amount - _armorDamageReduction);
			std::cout << _name << "\ttook\t" << amount - _armorDamageReduction << "\tdamages.ScavTrap style" << std::endl;
		}
	} else {
		std::cout << _name << "\tarmor absorbed damages.ScavTrap style" << std::endl;
	}
	std::cout << "\t\t" << _hitPoints << "\tleft." << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (amount + _hitPoints > _maxHitPoints) {
		_hitPoints = _maxHitPoints;
	} else {
		_hitPoints += amount;
	}
	std::cout << _name << "\thas been repaired for\t" << amount << "\thp.ScavTrap style" << std::endl;
	std::cout << "\t\t" << _hitPoints << "\tleft." << std::endl;
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


ScavTrap		&ScavTrap::operator=(ScavTrap const &rhs) {
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
