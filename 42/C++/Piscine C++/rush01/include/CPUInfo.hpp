#ifndef CPU_INFO_H
# define CPU_INFO_H

# include "IMonitorModule.hpp"
class IMonitorModule;

class CPUInfo: public IMonitorModule
{
public:
	CPUInfo(void);
	~CPUInfo(void);
	CPUInfo(CPUInfo const &src);
	CPUInfo&	operator=(CPUInfo const &rhs);

	virtual void							start(void);
	virtual void							refresh(void);
	virtual IMonitorModule::sData const		&getData(void) const;

protected:
private:
	IMonitorModule::sData	_data;
};

#endif
