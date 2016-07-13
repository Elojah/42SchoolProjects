#ifndef OUT_H
# define OUT_H

# include "IInstruction.hpp"
class IInstruction;

class Out : public IInstruction
{
public:
	Out(void);
	~Out(void);
	Out(Out const &src);
	Out&	operator=(Out const &rhs);

	virtual void	exec(int *i);
protected:
private:
};

#endif
