#ifndef VICTIM_H
# define VICTIM_H

# include <string>
# include <iostream>

class Victim
{
public:
	Victim(std::string const &name);
	virtual ~Victim(void);
	Victim(Victim const &src);
	Victim&	operator=(Victim const &rhs);
	const std::string	&getName(void) const;

	virtual void	getPolymorphed(void) const;
protected:
	std::string		_name;
private:
	Victim(void);
};

std::ostream&	operator<<(std::ostream& stream, Victim const &s);

#endif
