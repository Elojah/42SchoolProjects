#ifndef INCP_H
# define INCP_H

# include "IInstruction.hpp"
class IInstruction;

class Incp : public IInstruction
{
public:
	Incp(void);
	~Incp(void);
	Incp(Incp const &src);
	Incp&	operator=(Incp const &rhs);

	virtual void	exec(int *i);
protected:
private:
};

#endif
