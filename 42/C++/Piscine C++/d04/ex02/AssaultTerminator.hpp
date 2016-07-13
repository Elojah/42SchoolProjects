#ifndef ASSAULT_TERMINATOR_H
# define ASSAULT_TERMINATOR_H

# include "ISpaceMarine.hpp"
class ISpaceMarine;

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator(void);
	virtual ~AssaultTerminator(void);
	AssaultTerminator(AssaultTerminator const &src);
	AssaultTerminator&	operator=(AssaultTerminator const &rhs);

	virtual ISpaceMarine	*clone(void) const;
	virtual void			battleCry(void) const;
	virtual void			rangedAttack(void) const;
	virtual void			meleeAttack(void) const;

protected:
private:
};

#endif
