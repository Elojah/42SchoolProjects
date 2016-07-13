#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

# include <string>

class FragTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	void		vaulthunter_dot_exe(std::string const & target);
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	std::string	getName(void) const;
	size_t		getHitPoints(void) const;
	size_t		getMaxHitPoints(void) const;
	size_t		getEnergyPoints(void) const;
	size_t		getMaxEnergyPoints(void) const;
	size_t		getLevel(void) const;
	size_t		getMeleeAttackDamage(void) const;
	size_t		getRangedAttackDamage(void) const;
	size_t		getArmorDamageReduction(void) const;
	FragTrap&	operator=(FragTrap const &rhs);
protected:
private:
	struct sAtk {
		std::string	display;
		void		(FragTrap::*attack)(std::string const & target);
	};

	size_t		_hitPoints;
	size_t		_maxHitPoints;
	size_t		_energyPoints;
	size_t		_maxEnergyPoints;
	size_t		_level;
	size_t		_meleeAttackDamage;
	size_t		_rangedAttackDamage;
	size_t		_armorDamageReduction;
	std::string	_name;
};

#endif
