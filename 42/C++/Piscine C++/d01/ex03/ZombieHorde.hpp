#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H

# include <string>
class Zombie;

class ZombieHorde
{
public:
	ZombieHorde(int N);
	~ZombieHorde(void);
	void		announce(void);
protected:
private:
	ZombieHorde(void);

	Zombie		*_horde;
	int			_n;
};

#endif
