#ifndef FIXED_H
# define FIXED_H


class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed&				operator=(Fixed const &rhs);
	void				setRawBits(int const raw);
	int					getRawBits(void) const;
protected:
private:

	int					_value;
	static int const	_nbBits;
};

#endif
