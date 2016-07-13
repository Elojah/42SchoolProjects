#include "Board.hpp"
#include "Node.hpp"
#include "Rules.hpp"
#include <unistd.h>

#include <iostream>

const int	Board::_dir[E_DIRECTION] = {
	-BOARD_WIDTH,
	-BOARD_WIDTH + 1,
	1,
	BOARD_WIDTH + 1,
	BOARD_WIDTH,
	BOARD_WIDTH - 1,
	-1,
	-BOARD_WIDTH - 1
};

Board::Board(void)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		_cell[i] = Board::EMPTY;
		_playable[i] = 0;
	}
	_playable[BOARD_SIZE / 2] = 1;
	_root = new Node();
	_root->create();
}

Board::~Board(void)
{}

void		Board::exec(void)
{
	int		move;
	int		captures;
	Node	*tmp;
	eValue	player(Board::P1);

	_root->resetAlphaBeta();
	_root->calcMaxMin(*this, OPPONENT(player), REC_LVL, true);
	move = _root->getMax();
	std::cout << "move:\t" << move << std::endl;
	tmp = _root;
	_root = tmp->getChild(move);
	tmp->deleteExceptOne(move);
	while (play(move, OPPONENT(player), captures, true) < PTS_WIN)
	{
		display();
		std::cout << "Search max:\t" << std::endl;
		player = OPPONENT(player);
		_root->resetAlphaBeta();
		_root->calcMaxMin(*this, player, REC_LVL, true);
		move = _root->getMax();
		std::cout << "Play move:\t" << move << std::endl;
		tmp = _root;
		_root = tmp->getChild(move);
		tmp->deleteExceptOne(move);
	}
	display();
	std::cout << "Winner is:\t" << OPPONENT(player) << std::endl;
}

void		Board::display(void)
{
	write(1, "[---------------------------------------------]\n", 48);
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (i && !(i % BOARD_WIDTH))
			write(1, "\n", 1);
		if (_cell[i] == Board::P1)
			write(1, "1", 1);
		else if (_cell[i] == Board::P2)
			write(1, "2", 1);
		else if (_cell[i] == Board::EMPTY)
			write(1, "_", 1);
	}
	write(1, "\n", 1);
	write(1, "[---------------------------------------------]\n", 48);
}

void		Board::setValue(int const &n, eValue const &v)
{
	if (!IS_IN_RANGE(n))
		return ;
	_cell[n] = v;
}

void		Board::setPlayable(int const &n)
{
	++_playable[n];
	for (int i = 0; i < E_DIRECTION; ++i)
	{
		int		first;
		int		second;

		first = n + _dir[i];
		second = first + _dir[i];
		if (!IS_IN_RANGE(first))
			continue ;
		++_playable[first];
		if (!IS_IN_RANGE(second))
			continue ;
		++_playable[second];
	}
}

void		Board::unsetPlayable(int const &n)
{
	if (_playable[n] > 0)
		--_playable[n];
	for (int i = 0; i < E_DIRECTION; ++i)
	{
		int		first;
		int		second;
		first = n + _dir[i];
		second = first + _dir[i];
		if (!IS_IN_RANGE(first))
			continue ;
		if (_playable[first] > 0)
			--_playable[first];
		if (!IS_IN_RANGE(second))
			continue ;
		if (_playable[second] > 0)
			--_playable[second];
	}
}

bool		Board::isPlayable(int const &n)
{
	return (_playable[n] > 0);
}

Board::eValue const	&Board::operator[](int i) const
{
	static const Board::eValue	error = Board::ERROR;

	if (IS_IN_RANGE(i))
		return (_cell[i]);
	return (error);
}

int			Board::play(int const &n, eValue const &player
	, int &captures, bool calcResult)
{
	int		result(1);
	int		nPermissive(1);

	_cell[n] = player;
	setPlayable(n);
	captures = checkCapture(n);
	captureStone(n, captures, Board::EMPTY);
	if (Rules::win(*this, n, player))
		return (PTS_WIN);
	if (!calcResult)
		return (-1);
	for (int i = 0; i < 4; ++i)
	{
		int		tmp;
		if ((captures >> i) & 1)
			++result;
		if ((captures >> (i + 4)) & 1)
			++result;
		tmp = alignmentPermissive(n, i, player, nPermissive) +
					alignmentPermissive(n, i + 4, player, nPermissive) - 2;
		if (tmp > 0)
			result += tmp;
	}
	result += distToWall(n);
	return (result);/*FORBID return 0 !!!!!!!!!!*/
}

void		Board::unplay(int const &n, eValue const &player, int const &captures)
{
	_cell[n] = Board::EMPTY;
	unsetPlayable(n);
	captureStone(n, captures, OPPONENT(player));
}

/*PRIVATE AREA*/

int			Board::alignment(int const &n, int const &dir, eValue const &v) const
{
	if (!IS_IN_RANGE(n))
		return (0);
	if (_cell[n] == v)
		return (1 + alignment(n + _dir[dir], dir, v));
	else
		return (0);
}

int			Board::alignmentPermissive(int const &n, int const &dir
	, eValue const &v, int &permissive) const
{
	int			nextResult;

	if (_cell[n] == v)
	{
		if (IS_IN_RANGE(n + _dir[dir]))
			return (1 + alignmentPermissive(n + _dir[dir], dir, v, permissive));
		else
			return (-BOARD_SIZE - 1);
	}
	else if (_cell[n] == Board::EMPTY && permissive > 0)
	{
		if (IS_IN_RANGE(n + _dir[dir]))
		{
			--permissive;
			nextResult = alignmentPermissive(n + _dir[dir], dir, v, permissive);
			if (nextResult > 0)
				return (nextResult + 1);
			else
				++permissive;
		}
	}
	else if (_cell[n] == OPPONENT(v))
		return (-BOARD_SIZE - 1);
	return (0);
}

int			Board::checkCapture(int const &n) const
{
	int		result(0);

	for (int i = 0; i < E_DIRECTION; ++i)
	{
		int		next;
		next = n + 3 * _dir[i];
		if (alignment(n, i, OPPONENT(_cell[n])) == 2
			&& IS_IN_RANGE(next)
			&& _cell[next] == _cell[n])
			result |= 1 << i;
	}
	return (result);
}

void	Board::captureStone(int const &n, int const &captures, eValue const &v)
{
	if (!captures)
		return ;
	for (int i = 0; i < E_DIRECTION; ++i)
	{
		if ((captures >> i) & 1)
		{
			setValue(n + _dir[i], v);
			setValue(n + 2 * _dir[i], v);
		}
	}
}

int	Board::distToWall(int const &n)
{
	int	h;
	int	w;
	int	result(0);

	h = n / BOARD_WIDTH;
	w = n % BOARD_WIDTH;
	result += (h > BOARD_WIDTH / 2) ? BOARD_WIDTH - h : h;
	result += (w > BOARD_WIDTH / 2) ? BOARD_WIDTH - w : w;
	return (result / 2);
}
