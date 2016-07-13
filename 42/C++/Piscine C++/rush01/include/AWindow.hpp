#ifndef A_WINDOW_H
# define A_WINDOW_H

# include "IMonitorModule.hpp"
# include <ncurses.h>
# include <string>

class AWindow
{
public:
	AWindow(void);
	AWindow(int, int, int, int);
	virtual ~AWindow(void);
	AWindow(AWindow const &src);
	AWindow&	operator=(AWindow const &rhs);

	virtual void				init(void);

	WINDOW						*getWin(void) const;
	// const std::string	&getTitle(void) const;
	// int					getH(void) const;
	// int					getW(void) const;
	// int					getX(void) const;
	// int					getY(void) const;
	virtual void				serialize(std::ostream &stream) const;

	virtual std::string			readUser(void) const;
	virtual void				notifyUser(const std::string&) const;
	virtual void				setTitle(const std::string&);
	virtual void				printText(const std::string &str) const;
	virtual void				showGraph(IMonitorModule::sData &d) const;
protected:
	WINDOW				*_wwin;
	WINDOW				*_wuser;
	int					_wh;
	int					_ww;
	int					_wy;
	int					_wx;
	std::string			_wtitle;

	void				setDefaultSize(void);
private:
};

std::ostream&	operator<<(std::ostream& stream, AWindow const &s);

#endif
