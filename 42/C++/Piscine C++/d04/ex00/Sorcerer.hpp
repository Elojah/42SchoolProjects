#ifndef SORCERER_H
# define SORCERER_H

# include <string>
# include <iostream>
class Victim;

class Sorcerer
{
public:
	Sorcerer(std::string const &name, std::string const &title);
	~Sorcerer(void);
	Sorcerer(Sorcerer const &src);
	Sorcerer&	operator=(Sorcerer const &rhs);
	const std::string	&getName(void) const;
	const std::string	&getTitle(void) const;

	void	polymorph(Victim const &v) const;
protected:
private:
	Sorcerer(void);

	std::string		_name;
	std::string		_title;
};

std::ostream&	operator<<(std::ostream& stream, Sorcerer const &s);

#endif
