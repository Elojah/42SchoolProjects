#ifndef BASE_H
# define BASE_H

#include <iostream>

class Base
{
public:
	Base(void);
	virtual ~Base(void);
	Base(Base const &src);
	Base&	operator=(Base const &rhs);
protected:
private:
};

std::ostream&	operator<<(std::ostream& stream, Base const &s);

#endif
