#ifndef BOARD_HPP
# define BOARD_HPP

# define BOARD_SIZE 361
# define BOARD_WIDTH 19
# define PTS_WIN 1024
# define IS_IN_RANGE(n) ((n) >= 0 && (n) < BOARD_SIZE)
# define CAST_DIR(i) static_cast<Board::eDirection>(i)
# define REC_LVL 2

class Node;

class Board
{
public:
	Board(void);
	~Board(void);

	enum eValue
	{
		EMPTY = 0,
		P1,
		P2,
		ERROR,
		E_VALUE
	};

	enum eDirection
	{
		UP = 0,
		UP_RIGHT,
		RIGHT,
		DOWN_RIGHT,
		DOWN,
		DOWN_LEFT,
		LEFT,
		UP_LEFT,
		E_DIRECTION
	};

	void		exec(void);

	void		display(void);

	void		setValue(int const &n, eValue const &v);

	bool		isPlayable(int const &n);

	void		setPlayable(int const &n);
	void		unsetPlayable(int const &n);


	int			play(int const &n, eValue const &player, int &captures, bool calcResult);
	void		unplay(int const &n, eValue const &player, int const &captures);

	int			alignment(int const &n, int const &dir, eValue const &v) const;
	int			alignmentPermissive(int const &n, int const &dir
		, eValue const &v, int &permissive) const;


	Board::eValue const	&operator[](int i) const;

protected:
private:
	Board(Board const &src);
	Board&	operator=(Board const &rhs);

	int					checkCapture(int const &n) const;
	void					captureStone(int const &n, int const &captures, eValue const &v);
	int					distToWall(int const &n);

	static const int	_dir[E_DIRECTION];

	eValue				_cell[BOARD_SIZE];
	int					_playable[BOARD_SIZE];
	Node				*_root;
};

#endif
