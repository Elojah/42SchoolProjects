#ifndef I_MONITOR_DISPLAY_H
# define I_MONITOR_DISPLAY_H

# define REFRESH_TIME 500
# define ESCFL 65307
# define ESCNC 27
# define AFL 25
# define FLWWIDTH 600
# define FLWHEIGHT 200

# include <vector>
class IMonitorModule;

class IMonitorDisplay
{
public:
	virtual ~IMonitorDisplay(void){}
	virtual void			start(std::vector<IMonitorModule *> const &mods) = 0;
	virtual void			render(std::vector<IMonitorModule *> const &mods) = 0;
	virtual int				input(void) = 0;
protected:
private:
};

#endif
