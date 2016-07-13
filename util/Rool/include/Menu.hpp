#ifndef MENU_H
# define MENU_H

# define MAX_ITEMS 256

# include "Window.hpp"
# include <menu.h>
# include <string>
# include <vector>
# include <map>

class SortItems;

class Menu : public Window
{
public:
	typedef std::vector<std::string>	Strings;

	Menu(void);
	Menu(int, int, int, int);
	virtual ~Menu(void);

	void			userInput(void);

protected:
	typedef void	(Menu::*Callback)(ITEM *);
	typedef std::map<ITEM *, Callback> Items;
	typedef std::map<std::string, std::vector<std::map<std::string, std::string> > >	loopMap;

	MENU							*menu;
	WINDOW						*winMenu;
	/*Item map for callback*/
	Items							items;
	/*Final Items*/
	ITEM							*menuItems[MAX_ITEMS];
	SortItems					*sortObject;

	void				simpleCreate(const std::string&, const std::string&, const std::string&);
	void				loop(void);
	void				reset(void);
	void				createMenu(void);
	void				setMenuItems(void);

	/*
	**Usual callbacks
	*/
	void				errorCallback(ITEM *);
	void				endMenu(ITEM *);

	/*
	**Util
	*/
	void				addItem(const std::string&, Callback);
	virtual void			sortMenu(size_t length);
private:
	virtual void			createItems(void){}
};

#endif
