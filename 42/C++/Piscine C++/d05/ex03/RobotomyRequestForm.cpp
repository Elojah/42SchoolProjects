#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	Form("Robotomy Request", 72, 45),
	_target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
	Form("Robotomy Request", 72, 45) {
	if (this != &src)
		*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

std::string const		&RobotomyRequestForm::getTarget(void) const {
	return (_target);
}

void					RobotomyRequestForm::action(void) const
{
	std::cout << "* drrrrrrrrrrrrrrr *" << std::endl;
	std::srand(clock());
	if (std::rand() % 2)
	{
		std::cout << _target
				<< " has been robotomized successfully."
				<< std::endl;
	}
}

RobotomyRequestForm		&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}
