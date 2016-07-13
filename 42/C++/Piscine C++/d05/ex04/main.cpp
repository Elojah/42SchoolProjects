#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "Officeblock.hpp"

int				main(void)
{
	OfficeBlock	o;
	Intern		idiotOne;
	Bureaucrat	hermes("Hermes Conrad", 37);
	Bureaucrat	bob("Bobby Bobson", 123);
	OfficeBlock	ob(&bob, &hermes, &idiotOne);

	o.setIntern(&idiotOne);
	o.doBureaucracy("Help", "Help");
	o.setSigner(&bob);
	o.setExecutor(&hermes);
	o.doBureaucracy("Help", "Help");
	o.doBureaucracy("Shrubbery Creation", "help");
	ob.doBureaucracy("Presidential Pardon", "help");
	return (0);
}
