/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 13:05:53 by leeios            #+#    #+#             */
/*   Updated: 2015/08/10 17:35:43 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

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
	WINDOW					*_win;
	WINDOW					*_user;
	int							_h;
	int							_w;
	int							_y;
	int							_x;
	std::string			_title;

	const std::string			readUser(void) const;
	void									notifyUser(const std::string&) const;
	void									setTitle(const std::string&);
private:
	void									setDefaultSize(void);
};

#endif
