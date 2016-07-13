#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"

class Intern
{
private:
	Intern(Intern const &i);

	Intern			&operator=(Intern const &i);
public:
	Intern(void);
	~Intern(void);

	Form			*makeForm(std::string const &formName, std::string const &target);
};

#endif
