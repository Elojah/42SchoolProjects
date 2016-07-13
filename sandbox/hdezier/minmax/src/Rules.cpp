#include "Rules.hpp"

Rules::Rules(void)
{}

Rules::~Rules(void)
{}

bool		Rules::insertDoubleFreeThrees(Board const &b, int const &n,
	Board::eValue const &player)
{
	int						count(0);
	int						align1;
	int						align2;
	int						nPermissive;

	for (int i = 0; i < 4; ++i)
	{
		nPermissive = 1;
		align1 = b.alignmentPermissive(n, i, player, nPermissive) - 1;
		align2 = b.alignmentPermissive(n, i + 4, player, nPermissive) - 1;
		if ((align1 + align2 > 1 && nPermissive > 0)
			|| (align1 + align2 > 2 && nPermissive == 0))
			++count;
	}
	return (count > 1);
}

int		Rules::win(Board const &b, int const &n, Board::eValue const &player)
{
	int						result(0);
	int						align1;
	int						align2;

	for (int i = 0; i < 4; ++i)
	{
		align1 = b.alignment(n, i, player);
		align2 = b.alignment(n, i + 4, player);
		if (align1 + align2 > 5)
			result = result | (1 << i);
	}
	return (result);
}
