/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:00:51 by hdezier           #+#    #+#             */
//   Updated: 2016/05/18 17:16:16 by erobert          ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "Player.h"
#include "Board.h"

#include <iostream>

const common::vec2		Player::play(const IBoard &board, const Rules &rules
								, const common::vec2 &stroke, const common::eCell &player) const
{
	if (m_ai)
		return (calculusAI(board, rules, player));
	return (stroke);
}

const common::vec2		Player::calculusAI(const IBoard &board, const Rules &rules, const common::eCell &player) const
{
	common::vec2	result;
	sMinMaxState	minmaxState{MAX_DEPTH, true, player, {ERR_VAL, ERR_VAL}, {0, 0}, {0, ERR_VAL}};
	IBoard			*boardCopy;

	boardCopy = board.getCopy();

	if (player == common::eCell::P1)
		result = MinMax<sMax>::eval(*boardCopy, rules, minmaxState, m_eval_P1).coord;
	else
		result = MinMax<sMax>::eval(*boardCopy, rules, minmaxState, m_eval_P2).coord;
	delete (boardCopy);
	return (result);
}
