#include "Node.hpp"
#include "Rules.hpp"
#include <stddef.h>
#include <climits>
#include <iostream>

int Node::_alpha = INT_MIN;
int Node::_beta = INT_MAX;

Node::Node(void) :
	_children(NULL),
	_value(-1),
	_max(INT_MIN),
	_maxIndex(-1)
{}

Node::~Node(void)
{
	if (_children == NULL)
		return ;
	for (int i = 0; i < BOARD_SIZE; ++i) {
		delete (_children[i]);
	}
	delete [] _children;
}

void	Node::create(void)
{
	if (_children != NULL)
		return ;
	_children = new Node*[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; ++i) {
		_children[i] = new Node;
	}
}

void		Node::deleteExceptOne(int n) {
	if (_children == NULL)
		return ;
	for (int i = 0; i < BOARD_SIZE; ++i) {
		if (i == n)
			continue ;
		delete (_children[i]);
	}
	delete [] _children;
	_children = NULL;
}


int const	&Node::getMax(void) const
{
	return (_maxIndex);
}

Node	*Node::getChild(int n)
{
	if (_children == NULL)
		return (NULL);
	return (_children[n]);
}

void	Node::resetAlphaBeta(void)
{
	Node::_alpha = -1;
	Node::_beta = PTS_WIN + 1;
}

void	Node::calcMaxMin(Board &b, Board::eValue const &player
	, int rec, bool const &minmax)
{
	int			current;
	int			crtAlpha;
	int			crtBeta;

	if (minmax) {
		crtAlpha = Node::_alpha;
		crtBeta = Node::_beta;
	} else {
		crtAlpha = -Node::_beta;
		crtBeta = -Node::_alpha;
	}
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (b.isPlayable(i) && b[i] == Board::EMPTY
			&& !Rules::insertDoubleFreeThrees(b, i, player))
		{
			_children[i]->create();
			current = _children[i]->calculus(b, OPPONENT(player), i, rec - 1, !minmax);
			current *= minmax ? 1 : -1;
			if (current > _max)
			{
				_max = current;
				_maxIndex = i;
				if (_max > crtAlpha) {
					if (minmax) {
						Node::_alpha = _max;
					} else {
						Node::_beta = _max;
					}
					crtAlpha = _max;
					if (crtAlpha > crtBeta) {
						return ;
					}
				}
			}
		}
	}
}

int		Node::calculus(Board &b, Board::eValue const &player
	, int const &n, int rec, bool const &minmax)
{
	int			saveCaptures(0);

	_value = b.play(n, player, saveCaptures, true);
	if (rec == 0 || _value >= PTS_WIN) {
		b.unplay(n, player, saveCaptures);
		return (_value);
	} else {
		calcMaxMin(b, player, rec, minmax);
		b.unplay(n, player, saveCaptures);
		return (_max);
	}
}
