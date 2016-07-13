#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

# include <string>
# include "ClapTrap.hpp"
class ClapTrap;

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	void		vaulthunter_dot_exe(std::string const & target);
protected:
private:
};

#endif
