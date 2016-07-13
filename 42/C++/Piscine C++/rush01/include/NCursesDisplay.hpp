#ifndef N_CURSES_DISPLAY_H
# define N_CURSES_DISPLAY_H

# include "IMonitorDisplay.hpp"
class IMonitorDisplay;
# include "AWindow.hpp"
class AWindow;

class IMonitorModule;

# include <ncurses.h>
# include <string>
# include <vector>

class NCursesDisplay : public IMonitorDisplay, public AWindow
{
public:
	NCursesDisplay(void);
	NCursesDisplay(int h, int w, int y, int x);
	virtual ~NCursesDisplay(void);
	NCursesDisplay(NCursesDisplay const &src);
	NCursesDisplay&	operator=(NCursesDisplay const &rhs);

	virtual void			start(std::vector<IMonitorModule *> const &mods);
	virtual void			render(std::vector<IMonitorModule *> const &mods);
	virtual int				input(void);
protected:
private:
	std::vector<AWindow *>	_children;
};

#endif
