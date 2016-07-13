#ifndef HUMAN_H
# define HUMAN_H

# include <string>
# include "Brain.hpp"
class Brain;

class Human
{
public:
	Human(void);
	~Human(void);
	std::string			identify(void) const;
	const Brain			&getBrain(void) const;
protected:
private:
	const Brain			_b;
};

#endif
