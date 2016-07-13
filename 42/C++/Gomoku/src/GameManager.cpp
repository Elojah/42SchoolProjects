/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:39:44 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/18 19:17:41 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameManager.h"
#include <iostream>
#include <fstream>

template <uint8_t N>
void	GameManager<N>::displayWin(common::eCell winner) const
{
	if (winner == common::eCell::P1)
		std::cout << "P1 win !" << std::endl;
	else if (winner == common::eCell::P2)
		std::cout << "P2 win !" << std::endl;
	else if (winner == common::eCell::NONE)
		std::cout << "Draw !" << std::endl;
}

template <uint8_t N>
bool	GameManager<N>::loop(void)
{
	Player			*current_player;
	bool			valid;
	common::vec2	stroke;
	common::vec2	help;
	common::eCell	win;
	common::eCell	turn;
	uint16_t		tmp;
	std::clock_t	c_start;
	std::clock_t	c_end;
	float			time(0);

	turn = common::eCell::P1;
	m_uI.init(N);
	m_uI.render(m_board, m_player_1, m_player_2, turn,
				m_rules.capturedStones(), 0., help);
	while (!m_exit)
	{
		if (turn == common::eCell::P1)
			current_player = &m_player_1;
		else if (turn == common::eCell::P2)
			current_player = &m_player_2;
		if (!current_player->ai())
		{
			stroke = eventHandler();
			if (m_help)
			{
				help = current_player->calculusAI(m_board, m_rules, turn);
				m_help = false;
			}
		}
		c_start = std::clock();
		stroke = current_player->play(m_board, m_rules, stroke, turn);
		c_end = std::clock();
		if (current_player->ai())
			time = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
		valid = m_rules.isValid(m_board, stroke, turn);
		if (valid)
		{
			m_board.setCell(stroke, turn);
			auto n = m_rules.applyCapture(m_board, stroke, tmp);
			m_rules.addCapturedStones(n, turn);
			win = m_rules.gameEnded(m_board, stroke);
			if (win != common::eCell::E_CELL)
				break ;
			turn = (turn == common::eCell::P1) ? common::eCell::P2 :
				common::eCell::P1;
			help.x = 255;
		}
		m_uI.render(m_board, m_player_1, m_player_2, turn,
					m_rules.capturedStones(), time, help);
	}
	m_uI.renderWin(m_board, win);
	m_exit = false;
	while (!m_exit)
		eventHandler();
	return (m_restart);
}

template <uint8_t N>
void	GameManager<N>::_loadMap(const std::string &file)
{
	std::ifstream		ifs(file.c_str());
	std::string			line;
	uint8_t				x;
	uint8_t				y;

	x = 0;
	while (std::getline(ifs, line))
	{
		for (y = 0; y < line.size(); ++y)
		{
			const auto c = line[y];
			if (c == '1')
				m_board.setCell({x, y}, common::eCell::P1);
			else if (c == '2')
				m_board.setCell({x, y}, common::eCell::P2);
		}
		++x;
	}
}

template <uint8_t N>
common::vec2 const					&GameManager<N>::eventHandler(void)
{
	static common::vec2				stroke;
	static UserInterface::sEvent	event;

	stroke.x = ERR_VAL;
	stroke.y = ERR_VAL;
	event = m_uI.getEvent();
	if (event.e == UserInterface::EXIT)
		m_exit = true;
	else if (event.e == UserInterface::RESTART)
	{
		m_restart = true;
		m_exit = true;
	}
	if (event.e == UserInterface::MOUSE)
	{
		stroke.x = event.x;
		stroke.y = event.y;
	}
	else if (event.e == UserInterface::P1_AI)
		m_player_1.switchAI();
	else if (event.e == UserInterface::P2_AI)
		m_player_2.switchAI();
	else if (event.e == UserInterface::HELP)
		m_help = true;
	else if (event.e == UserInterface::PLAY)
		m_audio.playMusic(AudioManager::HYMNE_A_LA_KRO);
	else if (event.e == UserInterface::NEXT)
		m_audio.nextMusic();
	else if (event.e == UserInterface::STOP)
		m_audio.stopMusic();
	return (stroke);
}



template class GameManager<common::small>;
template class GameManager<common::medium>;
template class GameManager<common::large>;
