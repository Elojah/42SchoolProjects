#include "Human.hpp"

int		main(void) {
	Human	h;

	h.action("FUSRODAH", "TargetShout");
	h.action("meleeAttack", "TargetMelee");
	h.action("rangedAttack", "TargetRanged");
	return (0);
}
