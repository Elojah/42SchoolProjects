#include <string>
#include <iostream>

template<typename T>
T const	&min(T const &a, T const &b) {
	return (a < b ? a : b);
}

template<typename T>
T const	&max(T const &a, T const &b) {
	return (a > b ? a : b);
}

template<typename T>
void	swap(T &a, T &b) {
	T	tmp(a);

	a = b;
	b = tmp;
}

static void				ft_const(void) {
	int const			a(2);
	int const			b(3);
	std::string const	c("chaine1");
	std::string const	d("chaine2");

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int						main(void) {
	int					a(2);
	int					b(3);
	std::string			c("chaine1");
	std::string			d("chaine2");

	std::cout << "------const------" << std::endl;
	ft_const();
	std::cout << "-----------------" << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return (0);
}
