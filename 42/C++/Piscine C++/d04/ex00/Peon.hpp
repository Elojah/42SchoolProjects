#ifndef PEON_H
# define PEON_H

# include <string>
# include "Victim.hpp"
class Victim;

class Peon : public Victim
{
public:
	Peon(std::string const &name);
	virtual ~Peon(void);
	Peon(Peon const &src);
	Peon		&operator=(Peon const &rhs);

	virtual void	getPolymorphed(void) const;
protected:
private:
	Peon(void);
};

#endif
