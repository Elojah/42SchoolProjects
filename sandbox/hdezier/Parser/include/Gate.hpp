#ifndef GATE_H
# define GATE_H

# include "IToken.hpp"

class Gate : public IToken
{
public:
	Gate(void);
	~Gate(void);
	int				detect(const char &c);
	int				getPriority(void) const;
protected:
private:
};

#endif
