#ifndef MASTER_H
# define MASTER_H

# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"

class Master
{
public:
	Master(int nDisplay);
	~Master(void);
	Master(Master const &src);
	Master&	operator=(Master const &rhs);

	void			createModules(int nModules);
	void			loop(void);
	void			switchDisplay(int nDis);
protected:
private:
	Master(void);

	IMonitorDisplay						*_dis;
	std::vector<IMonitorModule *>		_mods;
};

#endif
