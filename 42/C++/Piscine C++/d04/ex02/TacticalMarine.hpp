#ifndef TACTICAL_MARINE_H
# define TACTICAL_MARINE_H

# include "ISpaceMarine.hpp"
class ISpaceMarine;

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine(void);
	virtual ~TacticalMarine(void);
	TacticalMarine(TacticalMarine const &src);
	TacticalMarine&	operator=(TacticalMarine const &rhs);

	virtual ISpaceMarine	*clone(void) const;
	virtual void			battleCry(void) const;
	virtual void			rangedAttack(void) const;
	virtual void			meleeAttack(void) const;

protected:
private:
};

#endif
