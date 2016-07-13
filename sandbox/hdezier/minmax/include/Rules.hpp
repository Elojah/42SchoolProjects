#ifndef RULES_HPP
# define RULES_HPP

# include "Board.hpp"

class Rules
{
public:
	Rules(void);
	~Rules(void);

	static bool		insertDoubleFreeThrees(Board const &b, int const &n,
		Board::eValue const &player);
	static int		win(Board const &b, int const &n, Board::eValue const &player);

protected:
private:
	Rules(Rules const &src);
	Rules&	operator=(Rules const &rhs);
};

#endif
