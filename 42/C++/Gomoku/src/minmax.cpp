/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 13:42:47 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/20 20:27:25 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minmax.h"

template<typename T>
const sMinMaxResult		MinMax<T>::eval(IBoard &board, const Rules &rules, const sMinMaxState &minMaxState, const IEval &evalFunction)
{

	if (minMaxState.depth == 0
		|| rules.gameEnded(board, minMaxState.lastStroke, minMaxState.captures[0], minMaxState.captures[1]) != common::eCell::E_CELL)
		return (((sMinMaxResult)
			{
				minMaxState.lastStroke
				, evalFunction.eval(board, rules, minMaxState)
			}));

	uint8_t					nCaptures(0);
	uint16_t				captures(0);
	sMinMaxResult			result;

	result.value = T::initialValue;

	uint8_t		alpha(minMaxState.alphaBeta[0]);
	uint8_t		beta(minMaxState.alphaBeta[1]);

	// Use iterator instead
	uint8_t		size = board.getSize();
	for (uint8_t i = 0; i < size; ++i)
	{
		for (uint8_t j = 0; j < size; ++j)
		{
			if (board.getHitBoard({i, j}) == false
				|| !rules.isValid(board, {i, j}, minMaxState.currentPlayer))
				continue ;

			board.setCell({i, j}, minMaxState.currentPlayer);
			nCaptures = rules.applyCapture(board, {i, j}, captures);

			const auto &next = T::search(
				board, rules
				, {
					(uint8_t)(minMaxState.depth - 1), !minMaxState.maximizing, OPPONENT(minMaxState.currentPlayer)
					, {i, j}
					, {
						(uint8_t)(minMaxState.currentPlayer == common::eCell::P1 ? minMaxState.captures[0] + nCaptures : minMaxState.captures[0])
						, (uint8_t)(minMaxState.currentPlayer == common::eCell::P1 ? minMaxState.captures[1] : minMaxState.captures[1] + nCaptures)
					}
					, {alpha, beta}
				}
				, evalFunction);

			rules.undoCapture(board, {i, j}, captures, OPPONENT(minMaxState.currentPlayer));
			board.setCell({i, j}, common::eCell::NONE);

			if (T::compareValues(next.value, result.value))
			{
				result.coord = {i, j};
				result.value = next.value;
			}

			if (T::alphaBetaComp(result.value, alpha, beta))
				return (result);
			T::setAlphaBeta(result.value, alpha, beta);
		}
	}
	return (result);
};

const sMinMaxResult	sMin::search(IBoard &board, const Rules &rules, const sMinMaxState &minMaxState, const IEval &evalFunction) {return (MinMax<sMax>::eval(board, rules, minMaxState, evalFunction));};
const sMinMaxResult	sMax::search(IBoard &board, const Rules &rules, const sMinMaxState &minMaxState, const IEval &evalFunction) {return (MinMax<sMin>::eval(board, rules, minMaxState, evalFunction));};
