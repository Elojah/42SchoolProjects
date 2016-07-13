// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUISFML.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/08 13:04:34 by erobert           #+#    #+#             //
//   Updated: 2015/04/09 21:31:46 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GUI_SFML_HPP
# define GUI_SFML_HPP

# include <sstream>
# include "SFML/Graphics.hpp"
# include "IGUINibbler.hpp"

class GUISFML: public IGUINibbler
{
public:
	GUISFML(void);
	~GUISFML(void);

	virtual void			initMap(std::vector<int> const &tMap,
									int height, int width);
	virtual void			updateDisplay(tNibbler const &tN, int apple,
										  int score);
	virtual Game::eEvent	getEvent(void);
private:
	int						_cellSize;
	std::vector<int>		_map;
	int						_height;
	int						_width;
	int						_input[Game::E_EVENT];
	sf::RenderWindow		_window;
	sf::Event				_event;
	sf::Texture				_tGrass;
	sf::Sprite				_sGrass;
	sf::Vector2f			_v;
	sf::RectangleShape		_w;
	sf::CircleShape			_a;
	sf::CircleShape			_h;
	sf::RectangleShape		_b;
	sf::Font				_f;
	sf::Text				_t;

	GUISFML(GUISFML const &gN);

	GUISFML					&operator=(GUISFML const &gN);
};

extern "C"
{
	GUISFML					*createGUI(void);
	void					deleteGUI(GUISFML *gN);
}

#endif
