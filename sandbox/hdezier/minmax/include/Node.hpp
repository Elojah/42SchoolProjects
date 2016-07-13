#ifndef NODE_HPP
# define NODE_HPP

# define OPPONENT(n) ((n) == Board::P1 ? Board::P2 : Board::P1)
# define INT_MAX 0xFFFFFF

#include "Board.hpp"

class Node
{
public:
	Node(void);
	~Node(void);

	void	calcMaxMin(Board &b, Board::eValue const &player,
							int rec, bool const &turn);
	void		create(void);
	int const	&getMax(void) const;
	void		deleteExceptOne(int n);
	Node		*getChild(int n);
	void		resetAlphaBeta(void);

protected:
private:

	Node(Node const &src);
	Node&	operator=(Node const &rhs);
	int			calculus(Board &b, Board::eValue const &player
					, int const &n, int rec, bool const &turn);

	Node			**_children;
	int				_value;
	int				_max;
	int				_min;
	int				_maxIndex;
	int				_minIndex;
	static int		_alpha;
	static int		_beta;
};

#endif
