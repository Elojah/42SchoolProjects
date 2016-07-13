#ifndef PUZZLE_H
# define PUZZLE_H

# include <vector>
# include <set>
# include <array>
# include <iostream>
# include "State.hpp"

# define BUF_SIZE 1024
# define MAX_DEPTH_SEARCH 10000
# define NONE_SET -1
# define DIST(a, b) (((a) > (b)) ? (a) - (b) : (b) - (a))

class IHeuristic;

class Puzzle
{
public:
	Puzzle(std::vector<int> &v, size_t size, int mask);
	~Puzzle(void);

	bool								solve(void);
	bool								isSolvable(void) const;
	void								printResult(void) const;
private:
	enum eMove
	{
		LEFT = 0,
		RIGHT,
		UP,
		DOWN,
	};
	struct sCmpState
	{
		bool operator() (State const &a, State const &b)
		{
			int		aV(a.getValue());
			int		bV(b.getValue());

			if (aV == bV)
				return (!(a == b));
			return (aV < bV);
		}
	};
	typedef std::set<State, sCmpState>	tStates;

	tStates								_openset;
	tStates								_closedset;
	size_t								_maxStates;
	size_t								_maxStatesOpen;
	State								_finalState;
	unsigned int						_size;
	std::vector<IHeuristic *>			_h;
	std::vector<IHeuristic *>			_heuristics;
	State								_solution;
	std::array<State, 5>				_expand;

	Puzzle(void);
	Puzzle(Puzzle const &p);

	Puzzle							&operator=(Puzzle const &p);

	void							assignHeuristics(void);
	void							setHeuristics(int mask);
	tStates::iterator				containState(State const &s);
	int								eval(State &s) const;
	void							expand(State const &s);
};

#endif
