#include "Enemy.hpp"

Enemy::Enemy(void) {
}

Enemy::Enemy(int hp, std::string const & type) :
	_type(type),
	_hp(hp) {
}

Enemy::Enemy(Enemy const &src) {
	if (this != &src)
		*this = src;
}

Enemy::~Enemy(void) {
}

std::string const	&Enemy::getType(void) const {
	return (_type);
}

int					Enemy::getHP(void) const {
	return (_hp);
}

void				Enemy::takeDamage(int amount) {
	if (!_hp)
		return ;
	if (amount > _hp) {
		_hp = 0;
	} else {
		_hp -= amount;
	}
}

Enemy		&Enemy::operator=(Enemy const &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
		_hp = rhs._hp;
	}
	return (*this);
}
