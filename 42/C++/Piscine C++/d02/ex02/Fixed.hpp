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

	Fixed&		operator=(Fixed const &rhs);
	void		setRawBits(int const raw);
	int			getRawBits(void) const;
	int			toInt(void) const;
	float		toFloat(void) const;

	bool			operator>(Fixed const &rhs) const;
	bool			operator<(Fixed const &rhs) const;
	bool			operator>=(Fixed const &rhs) const;
	bool			operator<=(Fixed const &rhs) const;
	bool			operator==(Fixed const &rhs) const;
	bool			operator!=(Fixed const &rhs) const;

	Fixed			operator+(Fixed const &rhs) const;
	Fixed			operator-(Fixed const &rhs) const;
	Fixed			operator*(Fixed const &rhs) const;
	Fixed			operator/(Fixed const &rhs) const;

	Fixed			operator++(int);
	Fixed			&operator++(void);
	Fixed			operator--(int);
	Fixed			&operator--(void);

	static Fixed	&min(Fixed const &a, Fixed const &b);
	static Fixed	&max(Fixed const &a, Fixed const &b);
protected:
private:

	int			_value;
	static int const	_nbBits;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& f);

#endif
