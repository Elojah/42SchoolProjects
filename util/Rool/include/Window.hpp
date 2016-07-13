#ifndef WINDOW_H
# define WINDOW_H

# include <ncurses.h>
# include <string>

class Window
{
public:
	Window(void);
	Window(int, int, int, int);
	virtual ~Window(void);
	WINDOW			*getWin(void) const;

protected:
	WINDOW			*win;
	WINDOW			*user;
	int					h;
	int					w;
	int					y;
	int					x;
	std::string			title;

	std::string			readUser(void) const;
	void				notifyUser(const std::string&) const;
	void				setTitle(const std::string&);
private:
	void				_setDefaultSize(void);
};

#endif
