#ifndef INC_H
# define INC_H

# include "IInstruction.hpp"
class IInstruction;

class Inc : public IInstruction
{
public:
	Inc(void);
	~Inc(void);
	Inc(Inc const &src);
	Inc&	operator=(Inc const &rhs);

	virtual void	exec(int *i);
protected:
private:
};

#endif
