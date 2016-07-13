#ifndef SPAN_H
# define SPAN_H

# include <exception>

class Span
{
public:
	Span(unsigned int N);
	~Span(void);
	Span(Span const &src);
	Span&	operator=(Span const &rhs);

	void			addNumber(int a);
	int				shortestSpan(void);
	int				longestSpan(void);

	void			addRange(int a, int b);
protected:
private:
	Span(void);

	int				*_container;
	unsigned int	_n;
	unsigned int	_i;
};

#endif
