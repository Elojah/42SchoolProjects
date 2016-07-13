#ifndef I_SQUAD_H
# define I_SQUAD_H

class ISpaceMarine;

class ISquad
{
public:
	virtual ~ISquad(void){}
	virtual int				getCount(void) const = 0;
	virtual ISpaceMarine	*getUnit(int) const = 0;
	virtual int				push(ISpaceMarine*) = 0;
protected:
private:
};

#endif
