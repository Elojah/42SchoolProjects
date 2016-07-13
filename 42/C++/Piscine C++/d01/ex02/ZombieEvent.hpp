#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

# include <string>
class Zombie;

class ZombieEvent
{
public:
	ZombieEvent(void);
	~ZombieEvent(void);
	void		setZombieType(const std::string &type);
	Zombie*		newZombie(std::string name) const;
protected:
private:
	std::string		_type;
};

#endif
