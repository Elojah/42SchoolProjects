#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

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
	SuperTrap	plust("POriginal");
	SuperTrap	plustJack("PJack");
	SuperTrap	plustBis(plust);

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
	ntJack.ninjaShoebox(nt);
	plust.vaulthunter_dot_exe("SuperTarget");
	plust.vaulthunter_dot_exe("SuperTarget");
	plust.vaulthunter_dot_exe("SuperTarget");
	plust.ninjaShoebox(ntJack);
	plust.takeDamage(50);
	return (0);
}
