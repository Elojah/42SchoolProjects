#include "Human.hpp"
#include <iostream>

Human::Human(void) {
	_actions[0].callback = &Human::meleeAttack;
	_actions[0].s = "meleeAttack";
	_actions[1].callback = &Human::rangedAttack;
	_actions[1].s = "rangedAttack";
	_actions[2].callback = &Human::intimidatingShout;
	_actions[2].s = "FUSRODAH";
}

Human::~Human(void) {
}

void		Human::meleeAttack(std::string const & target) {
	std::cout << "Melee attack on target:\t\t" << target << std::endl;
}

void		Human::rangedAttack(std::string const & target) {
	std::cout << "Ranged attack on target:\t" << target << std::endl;
}

void		Human::intimidatingShout(std::string const & target) {
	std::cout << "FUS RO DAH on target:\t\t" << target << std::endl;
}

void		Human::action(std::string const & action_name, std::string const & target) {
	for (std::size_t i = 0; i < 3; ++i) {
		if (action_name == _actions[i].s) {
			(this->*_actions[i].callback)(target);
		}
	}
}
