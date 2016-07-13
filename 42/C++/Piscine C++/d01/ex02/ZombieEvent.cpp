#include "ZombieEvent.hpp"
#include "Zombie.hpp"

ZombieEvent::ZombieEvent(void) {
}

ZombieEvent::~ZombieEvent(void) {
}

void	ZombieEvent::setZombieType(const std::string &type) {
	_type = std::string(type);
}

Zombie*		ZombieEvent::newZombie(std::string name) const {
	return (new Zombie(name, _type));
}
