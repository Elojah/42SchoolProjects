#ifndef CAT_H
# define CAT_H

# include "IMonitorModule.hpp"
class IMonitorModule;

class Cat : public IMonitorModule
{
public:
	Cat(void);
	~Cat(void);
	Cat(Cat const &src);
	Cat&	operator=(Cat const &rhs);

	virtual void							start(void);
	virtual void							refresh(void);
	virtual IMonitorModule::sData const		&getData(void) const;

protected:
private:
	IMonitorModule::sData	_data;
};

#endif
