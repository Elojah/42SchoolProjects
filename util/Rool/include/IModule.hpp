#ifndef I_MODULE_H
# define I_MODULE_H

# include <string>

class IModule
{
public:
	virtual ~IModule(void) {}
	virtual void		init(const std::string &path, const std::string &name) = 0;
protected:
private:
};

#endif
