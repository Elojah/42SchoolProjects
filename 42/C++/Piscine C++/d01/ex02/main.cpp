#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <stdlib.h>

static std::string		genRandom(void) {
	const static std::string		names[] = {
		"Igor", "Balor", "Tenor",
		"Arthrite", "Melior", "Kashiit",
		"Eros", "Matou", "Tremor", "Carios"
	};
	return (names[rand() % 10]);
}

static void		randomChump(ZombieEvent const &ze) {
	Zombie		*z;

	z = ze.newZombie(genRandom());
	z->announce();
	delete z;
}

int		main(void) {
	ZombieEvent	ze;

	ze.setZombieType("ZOMBIE EVENT");
	for (int i = 0; i < 15; ++i) {
		randomChump(ze);
	}
	return (0);
}
