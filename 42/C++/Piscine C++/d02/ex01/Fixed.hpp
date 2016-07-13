#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(int const value);
	Fixed(float const value);
	~Fixed(void);

	Fixed&				operator=(Fixed const &rhs);
	void				setRawBits(int const raw);
	int					getRawBits(void) const;
	int					toInt(void) const;
	float				toFloat(void) const;
protected:
private:

	int					_value;
	static int const	_nbBits;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& f);

#endif
