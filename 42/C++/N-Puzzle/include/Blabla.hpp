#ifndef BLABLA_H
# define BLABLA_H


class Blabla
{
public:
	Blabla(void);
	~Blabla(void);
	Blabla(Blabla const &src);
	Blabla&	operator=(Blabla const &rhs);
protected:
private:
};

std::ostream&	operator<<(std::ostream& stream, Blabla const &s);

#endif
