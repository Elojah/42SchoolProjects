#include "ZombieHorde.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde(int N) {
	if (N <= 0)
		return ;
	_horde = new Zombie[N]();
	_n = N;
}

ZombieHorde::ZombieHorde(void) {
}

ZombieHorde::~ZombieHorde(void) {
	delete[] this->_horde;
}

void		ZombieHorde::announce(void) {
	for (int i = 0; i < _n; ++i) {
		_horde[i].announce();
	}
}
