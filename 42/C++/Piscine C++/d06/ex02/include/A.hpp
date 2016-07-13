#ifndef A_H
# define A_H

# include "Base.hpp"
class Base;

class A : public Base
{
public:
	A(void);
	virtual ~A(void);
	A(A const &src);
	A&	operator=(A const &rhs);
protected:
private:
};

std::ostream&	operator<<(std::ostream& stream, A const &s);

#endif
