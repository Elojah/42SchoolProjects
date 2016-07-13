#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H

# include <iostream>
# include <fstream>
# include "Form.hpp"

class RobotomyRequestForm: public Form
{
public:
	RobotomyRequestForm(std::string const &target);
	virtual ~RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const &sCF);
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &sCF);

	std::string const		&getTarget(void) const;
	virtual void			action(void) const;

private:
	std::string const	_target;

	RobotomyRequestForm(void);
};
#endif
