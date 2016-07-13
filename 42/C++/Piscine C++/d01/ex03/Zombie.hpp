#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

class Zombie
{
public:
	Zombie(void);
	Zombie(std::string name, std::string type);
	~Zombie(void);
	void		announce(void) const;
protected:
private:
	std::string		_name;
	std::string		_type;
};

#endif
