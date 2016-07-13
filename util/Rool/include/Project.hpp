#ifndef PROJECT_H
# define PROJECT_H

# include "Menu.hpp"
# include <vector>
# include "ModuleFactory.hpp"

class Project : public Window
{
public:
					Project(const std::string&);
					virtual ~Project(void);
protected:
private:
	typedef IModule		*(ModuleFactory::*makeFn)(int, int, int, int);

	std::string		_path;
	std::string		_name;
	std::vector<IModule *>		_mods;
	ModuleFactory	_modsFactory;

					Project(void);

void		setModules(const std::string&);
void		initModules(void);

};

#endif
