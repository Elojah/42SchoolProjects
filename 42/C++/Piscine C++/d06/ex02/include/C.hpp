#ifndef C_H
# define C_H

# include "Base.hpp"
class Base;

class C : public Base
{
public:
	C(void);
	~C(void);
	C(C const &src);
	C&	operator=(C const &rhs);
protected:
private:
};

std::ostream&	operator<<(std::ostream& stream, C const &s);

#endif
