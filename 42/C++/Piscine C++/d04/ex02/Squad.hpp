#ifndef SQUAD_H
# define SQUAD_H

# include "ISquad.hpp"
class ISquad;

class Squad : public ISquad
{
public:
	Squad(void);
	virtual ~Squad(void);
	Squad(Squad const &src);
	Squad&	operator=(Squad const &rhs);

	virtual int				getCount(void) const;
	virtual ISpaceMarine	*getUnit(int) const;
	virtual int				push(ISpaceMarine*);

protected:
private:
	int				_count;
	ISpaceMarine	**_units;
};

#endif
