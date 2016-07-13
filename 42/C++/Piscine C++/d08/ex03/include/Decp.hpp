#ifndef DECP_H
# define DECP_H

# include "IInstruction.hpp"
class IInstruction;

class Decp : public IInstruction
{
public:
	Decp(void);
	~Decp(void);
	Decp(Decp const &src);
	Decp&	operator=(Decp const &rhs);

	virtual void	exec(int *i);
protected:
private:
};

#endif
