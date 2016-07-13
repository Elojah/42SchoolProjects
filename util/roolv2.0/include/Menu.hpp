/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 13:54:50 by leeios            #+#    #+#             */
/*   Updated: 2015/08/10 20:30:40 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_HPP
# define MENU_HPP

# define MAX_ITEMS 256

# define UP 'z'
# define DOWN 's'
# define SELECT 10
# define ESC 27

# include "Window.hpp"
# include <menu.h>
# include <string>
# include <vector>
# include <map>

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
	// typedef std::map<std::string, std::vector<std::map<std::string, std::string> > >	loopMap;


	MENU							*_menu;
	WINDOW						*_winMenu;
	/*Item map for callback*/
	Items							_items;
	/*Final Items*/
	ITEM							*_menuItems[MAX_ITEMS];

	void				simpleCreate(const std::string&);
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
	void							addItem(const std::string&, Callback);

private:
	/*
	**OVERLOAD ME !
	*/
	virtual void			sortItems(const int &length) = 0;
	virtual void			createItems(void) = 0;
};

#endif
