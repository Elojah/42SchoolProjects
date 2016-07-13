#ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H

# include <iostream>
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
public:
	ShrubberyCreationForm(std::string const &target);
	virtual ~ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &sCF);
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &sCF);

	std::string const		&getTarget(void) const;
	virtual void			action(void) const;

private:
	std::string const	_target;

	ShrubberyCreationForm(void);
};
#endif
