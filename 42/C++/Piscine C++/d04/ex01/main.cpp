#include <iostream>
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int		main(void)
{
	Character* zaz = new Character("zaz");
	Enemy* b = new RadScorpion();
	Enemy* c = new SuperMutant();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	std::cout << pr->getName()
			  << " "
			  << pr->getAPCost()
			  << " "
			  << pr->getDamage()
			  << std::endl;
	pr->attack();
	std::cout << pf->getName()
			  << " "
			  << pf->getAPCost()
			  << " "
			  << pf->getDamage()
			  << std::endl;
	pf->attack();
//	b->takeDamage(30);
	std::cout << b->getType()
			  << " "
			  << b->getHP()
			  << std::endl;
	c->takeDamage(30);
	std::cout << c->getType()
			  << " "
			  << c->getHP()
			  << std::endl;
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	delete pr;
	delete pf;
	delete zaz;
	delete c;
	return (0);
}
