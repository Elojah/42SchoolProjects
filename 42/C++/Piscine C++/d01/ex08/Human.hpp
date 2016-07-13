#ifndef HUMAN_H
# define HUMAN_H

# include <string>

class Human
{
private:
	void		meleeAttack(std::string const & target);
	void		rangedAttack(std::string const & target);
	void		intimidatingShout(std::string const & target);

	struct sAction {
		void			(Human::*callback)(std::string const &);
		std::string		s;
	};

	sAction		_actions[3];
public:
	Human(void);
	~Human(void);

	void		action(std::string const & action_name, std::string const & target);
};

#endif
