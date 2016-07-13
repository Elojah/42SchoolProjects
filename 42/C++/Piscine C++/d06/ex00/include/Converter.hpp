#ifndef CONVERTER_H
# define CONVERTER_H

# include <string>

class Converter
{
public:
	Converter(char const *av);
	~Converter(void);
	Converter(Converter const &src);
	Converter&	operator=(Converter const &rhs);

	void		toChar(std::ostream &stream) const;
	void		toInt(std::ostream &stream) const;
	void		toFloat(std::ostream &stream) const;
	void		toDouble(std::ostream &stream) const;

protected:
private:
	Converter(void);

	std::string		_str;
};

std::ostream&	operator<<(std::ostream& stream, Converter const &s);

#endif
