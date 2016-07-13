#ifndef NINJA_TRAP_H
# define NINJA_TRAP_H

# include <string>
# include "ClapTrap.hpp"
class ClapTrap;
class FragTrap;
class ScavTrap;

class NinjaTrap : virtual public ClapTrap
{
public:
	NinjaTrap(void);
	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap const &src);
	~NinjaTrap(void);
	void		ninjaShoebox(ClapTrap const &target);
	void		ninjaShoebox(FragTrap const &target);
	void		ninjaShoebox(ScavTrap const &target);
	void		ninjaShoebox(NinjaTrap const &target);

protected:
private:
};

#endif
