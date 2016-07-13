#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int	main(void) {
	FragTrap	ft("Original");
	FragTrap	ftJack("Jack");
	FragTrap	ftBis(ft);
	ScavTrap	st("SOriginal");
	ScavTrap	stJack("SJack");
	ScavTrap	stBis(st);
	NinjaTrap	nt("NOriginal");
	NinjaTrap	ntJack("NJack");
	NinjaTrap	ntBin(nt);

	ft.rangedAttack("Angel");
	ftBis.meleeAttack("AngelBis");
	ftJack.takeDamage(20);
	ftJack.takeDamage(2);
	ftJack.takeDamage(50);
	ftJack.takeDamage(300);
	ftJack.beRepaired(30);
	ftJack.beRepaired(300);
	ftJack.takeDamage(50);
	ftJack.vaulthunter_dot_exe("AngelR");
	ft.vaulthunter_dot_exe("AngelR");
	ft.vaulthunter_dot_exe("AngelR");
	ft.vaulthunter_dot_exe("AngelR");
	ft.vaulthunter_dot_exe("AngelR");
	ft.vaulthunter_dot_exe("AngelR");
	ft.vaulthunter_dot_exe("AngelR");
	stJack.challengeNewcomer();
	stJack.challengeNewcomer();
	stJack.challengeNewcomer();
	ntJack.ninjaShoebox(ft);
	ntJack.ninjaShoebox(st);
	ntJack.ninjaShoebox(ntBin);
	return (0);
}
