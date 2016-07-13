#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

# include <string>
# include "ClapTrap.hpp"
class ClapTrap;

class ScavTrap : public virtual ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);
	void		challengeNewcomer(void);
protected:
private:
};

#endif
