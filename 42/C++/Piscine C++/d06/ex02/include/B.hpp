#ifndef B_H
# define B_H

# include "Base.hpp"
class Base;

class B : public Base
{
public:
	B(void);
	virtual ~B(void);
	B(B const &src);
	B&	operator=(B const &rhs);
protected:
private:
};

std::ostream&	operator<<(std::ostream& stream, B const &s);

#endif
