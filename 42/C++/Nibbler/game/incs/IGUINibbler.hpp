// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IGUINibbler.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 18:56:56 by erobert           #+#    #+#             //
//   Updated: 2015/04/09 18:35:45 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef I_GUI_NIBBLER_HPP
# define I_GUI_NIBBLER_HPP

# include <list>
# include <vector>
# include "Game.hpp"

class IGUINibbler
{
public:
	typedef std::list<Game::sNibbler>	tNibbler;

	virtual ~IGUINibbler(void) {};

	virtual void			initMap(std::vector<int> const &map,
									int height, int width) = 0;
	virtual void			updateDisplay(tNibbler const &tN, int apple,
										  int score) = 0;
	virtual Game::eEvent	getEvent(void) = 0;
};

#endif
