#ifndef MODULE_FACTORY_H
# define MODULE_FACTORY_H

# include <string>
# include <map>

class IModule;

class ModuleFactory
{
public:
	typedef IModule		*(ModuleFactory::*makeFn)(int, int, int, int);
	ModuleFactory(void);
	~ModuleFactory(void);
	makeFn									makeModule(const std::string&);
protected:
private:
	static const std::map<std::string, makeFn>		allModules;
	static std::map<std::string, makeFn>				createAllModules(void);

	IModule										*makeClassList(int, int, int, int);
};

#endif
