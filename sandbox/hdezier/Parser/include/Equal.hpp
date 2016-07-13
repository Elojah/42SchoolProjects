#ifndef EQUAL_H
# define EQUAL_H

# include "IToken.hpp"

class Equal : public IToken
{
public:
	Equal(void);
	~Equal(void);
	int				detect(const char &c);
	int				getPriority(void) const;
protected:
private:
};

#endif
