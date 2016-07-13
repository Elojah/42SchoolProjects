#ifndef ENEMY_H
# define ENEMY_H

# include <string>

class Enemy
{
public:
	Enemy(int hp, std::string const & type);
	virtual ~Enemy(void);
	Enemy(Enemy const &src);
	Enemy				&operator=(Enemy const &rhs);

	std::string const	&getType(void) const;
	int					getHP(void) const;
	virtual void		takeDamage(int);

protected:
	std::string			_type;
	int					_hp;

private:
	Enemy(void);
};

#endif
