#ifndef O_S_INFO_H
# define O_S_INFO_H

# include "IMonitorModule.hpp"
class IMonitorModule;

class OSInfo: public IMonitorModule
{
public:
	OSInfo(void);
	~OSInfo(void);
	OSInfo(OSInfo const &src);
	OSInfo&	operator=(OSInfo const &rhs);

	virtual void							start(void);
	virtual void							refresh(void);
	virtual IMonitorModule::sData const		&getData(void) const;

protected:
private:
	IMonitorModule::sData	_data;
};

#endif
