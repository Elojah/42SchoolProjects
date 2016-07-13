/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:55:33 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/20 20:23:10 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include "common.h"

class IBoard;

class Rules
{
public:

	Rules(void);
	virtual ~Rules(void) = default;

	void					addCapturedStones(const uint8_t &n, const common::eCell &player);
	common::eCell			gameEnded(const IBoard &board, const common::vec2 &stroke, uint8_t capture_P1 = 0, uint8_t capture_P2 = 0) const;

	static bool				isValid(const IBoard &board, const common::vec2 &stroke, const common::eCell &turn);
	static uint8_t			applyCapture(IBoard &board, const common::vec2 &stroke, uint16_t &saveState);
	static void				undoCapture(IBoard &board, const common::vec2 &stroke, uint16_t &saveState, const common::eCell &player);

	inline uint8_t const	*capturedStones(void) const
	{
		return (m_capturedStones);
	};

private:
	uint8_t					m_capturedStones[2];

	static bool				_insertDoubleFreeThree(const IBoard &board, const common::vec2 &stroke, const common::eCell &turn);
	static bool				_alignFive(const IBoard &board, const common::vec2 &stroke);
	bool					_breakWin(const IBoard &board, const common::vec2 &stroke, uint8_t capture_P1, uint8_t capture_P2) const;
	bool					_breakWinByCapture(const IBoard &board, uint8_t capture_P1, uint8_t capture_P2, const common::eCell player) const;
};

#endif
