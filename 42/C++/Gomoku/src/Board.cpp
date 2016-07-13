/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:47:04 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/20 20:35:54 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Board.h"

template<uint8_t N>
int8_t			Board<N>::countAllAlign(const common::eCell &player) const
{
	bool			markMap[N][N];
	int8_t			result(0);

	for (uint8_t i = 0; i < N; ++i)
	{
		for (uint8_t j = 0; j < N; ++j)
			markMap[i][j] = false;
	}

	for (uint8_t i = 0; i < N; ++i)
	{
		for (uint8_t j = 0; j < N; ++j)
		{
			if (m_board[i][j] == common::eCell::NONE
				|| markMap[i][j] == true)
				continue ;
			common::eCell	startCell(m_board[i][j]);
			for (int8_t dir = -4; dir < 5; ++dir)
			{
				if (dir == 0)
					continue ;
				uint8_t			count(1);
				uint8_t			n(0);
				common::eCell	currentCell;
				while (++n)
				{
					currentCell = getCell({i, j}, (common::eDirection)dir, n);
					const auto	nextCellPosition = _convertCell({i, j}, (common::eDirection)dir, n);
					if (!_isValid(nextCellPosition)
						|| currentCell != startCell)
						break ;
					count *= (n + 1);
					markMap[nextCellPosition.x][nextCellPosition.y] = true;
				}
				if (dir > 0)
				{
					auto	alignFree = countAlignFree({i, j}, (common::eDirection)dir, startCell);
					count += alignFree * alignFree;
				}
				if (currentCell == common::eCell::NONE && count > 1)
				{
					count += 10;
					if (getCell({i, j}, common::opposite((common::eDirection)dir), 1) == common::eCell::NONE)
						count += 10;
				}
				if (startCell == player)
					result += count / 8;
				else
					result -= count / 2;
			}
		}
	}
	return (result);
};

template<uint8_t N>
int8_t	Board<N>::_countAlignSide(const common::vec2 &stroke, const common::eDirection &dir, const common::eCell &player, bool &permissive) const
{
	int					n;

	n = 0;
	while (++n < N)
	{
		auto	cell = getCell(stroke, dir, n);
		if (cell == player)
			continue ;
		else if (cell == common::eCell::NONE)
		{
			if (permissive && getCell(stroke, dir, n + 1) == player)
			{
				permissive = false;
				auto	nextCount = _countAlignSide(_convertCell(stroke, dir, n), dir, player, permissive);
				if (nextCount < 2)
				{
					permissive = true;
					return (n - 1);
				}
				else
					return (n + nextCount);
			}
			else
				return (n - 1);
		}
		else // NONE || E_CELL (=out of range)
			return (-1);
	}
	return (0);
}


template class Board<common::small>;
template class Board<common::medium>;
template class Board<common::large>;
