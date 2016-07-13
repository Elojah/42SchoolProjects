#ifndef I_INSTRUCTION_H
# define I_INSTRUCTION_H

class IInstruction
{
public:
	virtual ~IInstruction(void){}
	virtual void	exec(int *i) = 0;
protected:
private:
};

#endif
