#ifndef SUPER_TRAP_H
# define SUPER_TRAP_H

# include <string>

# include "NinjaTrap.hpp"
class NinjaTrap;

# include "FragTrap.hpp"
class FragTrap;

class SuperTrap : public NinjaTrap, public FragTrap
{
public:
	SuperTrap(void);
	SuperTrap(std::string name);
	SuperTrap(SuperTrap const &src);
	~SuperTrap(void);
protected:
private:
};

#endif
