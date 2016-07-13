#include "FragTrap.hpp"

int	main(void) {
	FragTrap	ft("Original");
	FragTrap	ftJack("Jack");
	FragTrap	ftBis(ft);

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
	return (0);
}
