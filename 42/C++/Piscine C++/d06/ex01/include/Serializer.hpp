#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <string>

class Serializer
{
public:
	Serializer(void);
	~Serializer(void);
	Serializer(Serializer const &src);
	Serializer&	operator=(Serializer const &rhs);

	struct Data {
		std::string		s1;
		int				n;
		std::string		s2;
	};

	void				*generate(void);
	Serializer::Data	*discover(void *raw);
protected:
private:
};

std::ostream&	operator<<(std::ostream& stream, Serializer const &s);

#endif
