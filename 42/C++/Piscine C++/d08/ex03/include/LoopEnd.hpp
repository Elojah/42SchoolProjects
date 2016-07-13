#ifndef LOOP_END_H
# define LOOP_END_H

# include "IInstruction.hpp"
class IInstruction;

class LoopEnd : public IInstruction
{
public:
	LoopEnd(void);
	~LoopEnd(void);
	LoopEnd(LoopEnd const &src);
	LoopEnd&	operator=(LoopEnd const &rhs);

	virtual void	exec(int *i);
protected:
private:
};

#endif
