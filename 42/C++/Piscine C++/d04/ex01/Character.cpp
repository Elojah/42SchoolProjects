#include "Character.hpp"
#include "Enemy.hpp"
#include "AWeapon.hpp"
#include <iostream>

Character::Character(void) {
}

Character::Character(std::string const & name) :
	_name((name)),
	_ap(40),
	_weapon(NULL) {
}

Character::Character(Character const &src) :
	_name(src._name),
	_ap(40),
	_weapon(NULL) {
	if (this != &src)
		*this = src;
}

Character::~Character(void) {
}

void				Character::recoverAP(void) {
	_ap += 10;
	if (_ap > 40)
		_ap = 40;
}

void				Character::equip(AWeapon *weapon) {
	_weapon = weapon;
}

void				Character::attack(Enemy *enemy) {
	size_t			cost;

	cost = _weapon->getAPCost();
	if (!_weapon || cost > _ap)
		return ;
	_ap -= cost;
	std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
	_weapon->attack();
	enemy->takeDamage(_weapon->getDamage());
	if (enemy->getHP() <= 0)
		delete enemy;
}

std::string const	&Character::getName(void) const {
	return (_name);
}

size_t				Character::getAPLeft(void) const {
	return (_ap);
}

AWeapon				*Character::getWeapon(void) const {
	return (_weapon);
}

Character		&Character::operator=(Character const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, Character const &s) {
	AWeapon		*weapon;

	weapon = s.getWeapon();
	if (weapon)
		stream << s.getName() << " has " << s.getAPLeft() << " AP and wields a " << weapon->getName() << std::endl;
	else
		stream << s.getName() << " has " << s.getAPLeft() << " AP and is unarmed " << std::endl;
	return (stream);
}
