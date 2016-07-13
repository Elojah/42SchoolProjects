#include <array>
#include <algorithm>
#include "Puzzle.hpp"
#include "State.hpp"
#include "Manhattan.hpp"
#include "LinearConflict.hpp"
#include "Hamming.hpp"
#include "MaxSwap.hpp"
#include "NTiles.hpp"

Puzzle::Puzzle(std::vector<int> &v, size_t size, int mask):
	_maxStates(0),
	_maxStatesOpen(1),
	_size(size)
{
	State						s;
	std::array<int, MAX_CASE>	tmp;
	size_t						n(0);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		tmp[n++] = (*it);
	_finalState = State(_size, std::array<int, MAX_CASE>{{}});
	_finalState.finalFillArray();
	assignHeuristics();
	std::cout << "Nb available heuristics:\t"
			  << _heuristics.size() << std::endl;
	setHeuristics(mask);
	std::cout << "Nb heuristics specified:\t" << _h.size() << std::endl;
	s = State(_size, tmp);
	s.setPrevious(0);
	eval(s);
	_openset.insert(s);
	std::cout << "Initial state: " << std::endl;
	s.display();
	std::cout << "to final state: " << std::endl;
	_finalState.display();
}
Puzzle::~Puzzle(void)
{
	for (std::vector<IHeuristic *>::const_iterator it = _heuristics.begin(); it != _heuristics.end(); ++it)
		delete (*it);
}

void							Puzzle::assignHeuristics(void)
{
	_heuristics.push_back(new Manhattan(_finalState));
	_heuristics.push_back(new NTiles(_finalState));
	_heuristics.push_back(new Hamming(_finalState));
	_heuristics.push_back(new LinearConflict(_finalState));
	_heuristics.push_back(new MaxSwap(_finalState));
}

void							Puzzle::setHeuristics(int mask)
{
	size_t						i;

	for (i = 0; i < _heuristics.size(); ++i)
	{
		if (mask & (1 << i))
			_h.push_back(_heuristics[i]);
	}
}

bool							Puzzle::isSolvable(void) const
{
	MaxSwap						valid(_finalState);
	size_t						allPermutations;
	size_t						emptyPermutations;
	size_t						startEmpty;
	size_t						finalEmpty;
	size_t						x;
	size_t						y;

	startEmpty = (*(_openset.begin())).getEmpty();
	finalEmpty = _finalState.getEmpty();
	allPermutations = valid.eval(*(_openset.begin()));
	x = startEmpty % _size;
	y = finalEmpty % _size;
	emptyPermutations = (startEmpty > finalEmpty ?
						 startEmpty / _size - finalEmpty / _size + DIST(x, y)
						 : finalEmpty / _size - startEmpty / _size + DIST(x, y));
	return ((_size % 2 && (emptyPermutations % 2) == (allPermutations % 2))
		|| (_size % 2 == 0 && (allPermutations % 2 == 0)));
}

int								Puzzle::eval(State &s) const
{
	int							result;

	if ((result = s.getValue()) != NONE_SET)
		return (result);
	result = 0;
	for (std::vector<IHeuristic *>::const_iterator it = _h.begin(); it != _h.end(); ++it)
		result += (*it)->eval(s);
	s.setValue(result);
	return (result);
}
void							Puzzle::expand(State const &s)
{
	size_t						empty(s.getEmpty());
	size_t						current(0);

	if (empty % _size > 0)
		_expand[current++] = State(s, LEFT);
	if (empty % _size < _size - 1)
		_expand[current++] = State(s, RIGHT);
	if (empty /_size > 0)
		_expand[current++] = State(s, UP);
	if (empty / _size < _size - 1)
		_expand[current++] = State(s, DOWN);
	_expand[current].setPrevious(0);
}
Puzzle::tStates::iterator		Puzzle::containState(State const &s)
{
	tStates::iterator			i;

	for (i = _closedset.begin(); i != _closedset.end(); ++i)
	{
		if (i->getValue() > s.getValue())
			return (_closedset.end());
		if (s == *i)
			return (i);
	}
	return (_closedset.end());
}

bool									Puzzle::solve(void)
{
	State								tmp;
	bool								isInClosed;
	size_t								previous;
	std::pair<tStates::iterator, bool>	inOpen;
	tStates::iterator					inClosed;
	tStates::iterator					inSet;
	tStates::const_iterator				e;
	std::array<State, 5>::iterator		is;
	char								input[256];

	std::cout << "Solving puzzle ... Please wait for few seconds ..."
			  << std::endl;
	while (_openset.size() > 0)
	{
		if (_openset.size() > _maxStatesOpen)
			_maxStatesOpen = _openset.size();
		e = _openset.begin();
		if (*e == _finalState)
		{
			_solution = *e;
			std::cout << "Success !" << std::endl;
			return (true);
		}
		previous = e->getId();
		expand(*e);
		_closedset.insert(*e);
		_openset.erase(e);
		for (is = _expand.begin(); is->getPrevious() != 0; ++is)
		{
			eval(*is);
			inClosed = containState(*is);
			isInClosed = (inClosed != _closedset.end());
			if (isInClosed)
				inSet = inClosed;
			else
			{
				inOpen = _openset.insert(*is);
				if (inOpen.second == true)
					continue ;
				inSet = inOpen.first;
			}
			if (is->getDepth() < inSet->getDepth())
			{
				tmp = *inSet;
				tmp.setPrevious(previous);
				_openset.insert(inSet, tmp);
				if (isInClosed)
					_closedset.erase(inSet);
				else
					_openset.erase(inSet);
			}
		}
		_maxStates++;
		if (_maxStates % 1000 == 0)
			std::cout << _maxStates << " states tested." << std::endl;
		if (_maxStates % MAX_DEPTH_SEARCH == 0)
		{
			if (_maxStates == MAX_DEPTH_SEARCH * 2)
			{
				std::cout << "You're going damn too far, stop it right now !"
						  << std::endl;
				break ;
			}
			std::cout << _maxStates
					  << " states have been tested, continue ? y/n"
					  << std::endl;
			std::cin.get(input, 256);
			if (input[0] != 'y')
				break ;
		}
	}
	return (false);
}

void						Puzzle::printResult(void) const
{
	char					input[256];
	std::vector<State>		path;
	size_t					tmp;
	tStates::iterator		itState;

	std::cout << "◦ Total number of states ever selected "
			  << "in the opened set:\t\t\t\t" << _maxStatesOpen << std::endl;
	std::cout << "◦ Maximum number of states ever represented "
			  << "in memory at the same time:\t\t\t" 
			  << _openset.size() + _closedset.size() << std::endl;
	std::cout << "◦ Number of moves required to transition "
			  << "from the initial state to the final state:\t" 
			  << _solution.getDepth() << std::endl;
	std::cout << "Print result ? y/n" << std::endl;
	std::cin.get(input, 256);
	tmp = _solution.getPrevious();
	if (input[0] != 'y')
		return ;
	while (tmp != 0)
	{
		itState = std::find_if(_closedset.begin(), _closedset.end(),
			[&] (State const &s) {
				return (s.getId() == tmp);
			}
		);
		path.insert(path.begin(), *itState);
		tmp = itState->getPrevious();
	}
	for (std::vector<State>::iterator it = path.begin(); it != path.end(); ++it)
		it->display();
	_solution.display();
}
