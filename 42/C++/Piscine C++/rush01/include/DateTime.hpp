#ifndef DATE_TIME_H
# define DATE_TIME_H

# include "IMonitorModule.hpp"
class IMonitorModule;

class DateTime : public IMonitorModule
{
public:
	DateTime(void);
	~DateTime(void);
	DateTime(DateTime const &src);
	DateTime&	operator=(DateTime const &rhs);

	virtual void						start(void);
	virtual void						refresh(void);
	virtual IMonitorModule::sData const	&getData(void) const;
protected:
private:
	IMonitorModule::sData	_data;
};

#endif
