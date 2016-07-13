#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

# include <iostream>
# include <fstream>
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
public:
	PresidentialPardonForm(std::string const &target);
	virtual ~PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const &sCF);
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &sCF);

	std::string const		&getTarget(void) const;
	virtual void			action(void) const;

private:
	std::string const	_target;

	PresidentialPardonForm(void);
};
#endif
