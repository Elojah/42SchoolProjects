#ifndef DEC_H
# define DEC_H

# include "IInstruction.hpp"
class IInstruction;

class Dec : public IInstruction
{
public:
	Dec(void);
	~Dec(void);
	Dec(Dec const &src);
	Dec&	operator=(Dec const &rhs);

	virtual void	exec(int *i);
protected:
private:
};

#endif
