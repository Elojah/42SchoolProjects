#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	Form("Presidential Pardon", 25, 5),
	_target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
	Form("Presidential Pardon", 25, 5) {
	if (this != &src)
		*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

std::string const		&PresidentialPardonForm::getTarget(void) const {
	return (_target);
}

void					PresidentialPardonForm::action(void) const
{
	std::cout << _target
			<< " has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm		&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}
