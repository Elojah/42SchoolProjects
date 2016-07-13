#ifndef RAM_INFO_H
# define RAM_INFO_H

# include "IMonitorModule.hpp"


class IMonitorModule;

class RAMInfo: public IMonitorModule
{
public:
	RAMInfo(void);
	~RAMInfo(void);
	RAMInfo(RAMInfo const &src);
	RAMInfo&	operator=(RAMInfo const &rhs);

	virtual void							start(void);
	virtual void							refresh(void);
	virtual IMonitorModule::sData const		&getData(void) const;
	void									addNewValueToGraph(unsigned int percentage);

protected:
private:
	IMonitorModule::sData	_data;
};

#endif
