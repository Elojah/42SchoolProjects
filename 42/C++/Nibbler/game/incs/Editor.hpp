// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Editor.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:35:21 by erobert           #+#    #+#             //
//   Updated: 2015/04/10 15:07:20 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EDITOR_HPP
# define EDITOR_HPP

# include <ncurses.h>
# include <vector>
# include "Game.hpp"

class Editor
{
public:
	Editor(void);
	~Editor(void);

	std::vector<int> const	&map(void) const;

	void					createMap(void);
private:
	std::vector<int>		_map;

	Editor(Editor const &e);

	Editor					&operator=(Editor const &e);

	void					removeCursor(int i);
	void					addCursor(int i);
};

#endif
