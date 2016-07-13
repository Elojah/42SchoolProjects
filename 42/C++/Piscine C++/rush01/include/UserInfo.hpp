#ifndef USER_INFO_H
# define USER_INFO_H

# include "IMonitorModule.hpp"
class IMonitorModule;

class UserInfo : public IMonitorModule
{
public:
	UserInfo(void);
	~UserInfo(void);
	UserInfo(UserInfo const &src);
	UserInfo&	operator=(UserInfo const &rhs);

	virtual void							start(void);
	virtual void							refresh(void);
	virtual IMonitorModule::sData const		&getData(void) const;
protected:
private:
	IMonitorModule::sData	_data;
};

#endif
