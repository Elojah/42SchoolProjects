#ifndef IN_H
# define IN_H

# include "IInstruction.hpp"
class IInstruction;

class In : public IInstruction
{
public:
	In(void);
	~In(void);
	In(In const &src);
	In&	operator=(In const &rhs);

	virtual void	exec(int *i);
protected:
private:
};

#endif
