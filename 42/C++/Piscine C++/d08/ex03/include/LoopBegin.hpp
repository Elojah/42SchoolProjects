#ifndef LOOP_BEGIN_H
# define LOOP_BEGIN_H

# include "IInstruction.hpp"
class IInstruction;

class LoopBegin : public IInstruction
{
public:
	LoopBegin(void);
	~LoopBegin(void);
	LoopBegin(LoopBegin const &src);
	LoopBegin&	operator=(LoopBegin const &rhs);

	virtual void	exec(int *i);
protected:
private:
};

#endif
