#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int			main(void)
{
	Intern	i;
	Form	*rrf;

	std::cout << "------------------------" << std::endl;
	rrf = i.makeForm("robotomy request", "Bender");
	rrf = i.makeForm("Robotomy Request", "Bender");
	delete rrf;
	rrf = i.makeForm("Shrubbery Creation", "Bender");
	delete rrf;
	rrf = i.makeForm("Presidential Pardon", "Bender");
	delete rrf;
	rrf = i.makeForm("Robotomy Requ1est", "Bender");
	delete rrf;
	std::cout << "------------------------" << std::endl;
	return (0);
}
