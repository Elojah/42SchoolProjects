#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {
}
Intern::~Intern(void) {
}

Form			*Intern::makeForm(std::string const &formName, std::string const &target) {
	Form		*f;

	if (formName.compare("Robotomy Request") == 0)
		f = new RobotomyRequestForm(target);
	else if (formName.compare("Shrubbery Creation") == 0)
		f = new ShrubberyCreationForm(target);
	else if (formName.compare("Presidential Pardon") == 0)
		f = new PresidentialPardonForm(target);
	else
	{
		std::cout << "Intern couldn't find " << formName << "." << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << formName << "." << std::endl;
	return (f);
}
