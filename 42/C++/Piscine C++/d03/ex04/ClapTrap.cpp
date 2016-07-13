#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) :
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

ClapTrap::ClapTrap(std::string name) :
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

ClapTrap::ClapTrap(ClapTrap const &src) {
	*this = src;
	std::cout << _name << "\t--\tstart bootup sequence." << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << _name << "\t--\tNo, nooo, you are so STUPID!"  << std::endl;
}

std::string	ClapTrap::getName(void) const {return (_name);}
size_t		ClapTrap::getHitPoints(void) const {return (_hitPoints);}
size_t		ClapTrap::getMaxHitPoints(void) const {return (_maxHitPoints);}
size_t		ClapTrap::getEnergyPoints(void) const {return (_energyPoints);}
size_t		ClapTrap::getMaxEnergyPoints(void) const {return (_maxEnergyPoints);}
size_t		ClapTrap::getLevel(void) const {return (_level);}
size_t		ClapTrap::getMeleeAttackDamage(void) const {return (_meleeAttackDamage);}
size_t		ClapTrap::getRangedAttackDamage(void) const {return (_rangedAttackDamage);}
size_t		ClapTrap::getArmorDamageReduction(void) const {return (_armorDamageReduction);}

void	ClapTrap::rangedAttack(std::string const & target) {
	std::cout << _name << "\tattacks\t" << target << "\twith ranged attack." << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target) {
	std::cout << _name << "\tattacks\t" << target << "\twith melee attack." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
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

void	ClapTrap::beRepaired(unsigned int amount) {
	if (amount + _hitPoints > _maxHitPoints) {
		_hitPoints = _maxHitPoints;
	} else {
		_hitPoints += amount;
	}
	std::cout << _name << "\thas been repaired for\t" << amount << "\thp." << std::endl;
	std::cout << "\t\t" << _hitPoints << "\tleft." << std::endl;
}

ClapTrap		&ClapTrap::operator=(ClapTrap const &rhs) {
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
