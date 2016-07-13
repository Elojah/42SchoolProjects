/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:01:31 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/18 16:46:07 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINMAX_H
# define MINMAX_H

# include "common.h"
# include "Board.h"
# include "Rules.h"

# include <iostream>

struct	sMin;
struct	sMax;

// Helper struct
struct					sMinMaxState
{
	const uint8_t		depth;
	const bool			maximizing;
	const common::eCell	currentPlayer;
	const common::vec2	lastStroke;
	const uint8_t		captures[2];
	const uint8_t		alphaBeta[2];
};

struct					sMinMaxResult
{
	common::vec2		coord;
	uint8_t				value;
};

struct					IEval
{
	virtual uint8_t		eval(const IBoard &board, const Rules &rules, const sMinMaxState &minMaxState) const = 0;
};

// Extern class
template<typename T>
class		MinMax
{

public:
	static const sMinMaxResult	eval(IBoard &board, const Rules &rules, const sMinMaxState &minMaxState, const IEval &evalFunction);

private:
};

struct	sMin
{
	static const sMinMaxResult	search(IBoard &board, const Rules &rules, const sMinMaxState &minMaxState, const IEval &evalFunction);
	inline static bool			compareValues(const uint8_t nextValue, const uint8_t currentValue) {return (nextValue < currentValue);};
	inline static bool			alphaBetaComp(uint8_t value, uint8_t alpha, uint8_t __attribute__((unused))beta) {return (alpha >= value);};
	inline static void			setAlphaBeta(uint8_t value, uint8_t __attribute__((unused))&alpha, uint8_t &beta) {beta = std::min(beta, value);};
	static const uint8_t		initialValue = ERR_VAL;
};

struct	sMax
{
	static const sMinMaxResult	search(IBoard &board, const Rules &rules, const sMinMaxState &minMaxState, const IEval &evalFunction);
	inline static bool			compareValues(const uint8_t nextValue, const uint8_t currentValue) {return (nextValue > currentValue);};
	inline static bool			alphaBetaComp(uint8_t value, uint8_t __attribute__((unused))alpha, uint8_t beta) {return (value >= beta);};
	inline static void			setAlphaBeta(uint8_t value, uint8_t &alpha, uint8_t __attribute__((unused))&beta) {alpha = std::max(alpha, value);};
	static const uint8_t		initialValue = 0;
};

#endif
