#ifndef BRAIN_H
# define BRAIN_H

# include <string>

class Brain
{
public:
	Brain(void);
	~Brain(void);
	std::string		identify(void) const;
protected:
private:
	std::string		_id;
};

#endif
