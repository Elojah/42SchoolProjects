/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:47:10 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/20 20:19:59 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

# include "stdint.h"
# include "common.h"
# include "Rules.h"
# include <cstring>
# include <utility>
# include <unistd.h>

class IBoard
{
public:
	virtual ~IBoard(void) {};
	virtual void			setCell(const common::vec2 &stroke, const common::eCell &player) = 0;
	virtual void			setCell(const common::vec2 &origin, common::eDirection dir, uint8_t dist, const common::eCell &player) = 0;
	virtual common::eCell	getCell(const common::vec2 &coord) const = 0;
	virtual common::eCell	getCell(const common::vec2 &origin, common::eDirection dir, uint8_t dist) const = 0;
	virtual bool			isCaptPosition(const common::vec2 &position) const = 0;
	virtual bool			isCaptPosition(const common::vec2 &origin, common::eDirection dir, uint8_t dist) const = 0;
	virtual bool			getHitBoard(const common::vec2 &coord) const = 0;
	virtual uint8_t			getSize(void) const = 0;
	virtual IBoard			*getCopy(void) const = 0;
	virtual int8_t			countAlignFree(const common::vec2 &stroke, const common::eDirection &dir, const common::eCell &player, bool permissive = true) const = 0;
	virtual int8_t			countAlign(const common::vec2 &stroke, const common::eDirection &dir, const common::eCell &player) const = 0;
	virtual int8_t			countAllAlign(const common::eCell &player) const = 0;
};

template <uint8_t N>
class	Board : public IBoard
{

public:
	inline Board(void) {reset();};

	inline Board(const IBoard &copy) {(void)copy;};

	inline virtual ~Board(void) {};

	inline virtual void				*getBoardPtr(void) const {return ((void *)&m_board);};
	inline virtual void				*getHitBoardPtr(void) const {return ((void *)&m_hitBoard);};
	inline virtual uint8_t			getSize(void) const {return (N);};
	inline virtual IBoard			*getCopy(void) const
	{
		Board<N>					*result;

		result = new Board<N>;
		memcpy(result->getBoardPtr(), m_board, sizeof(m_board));
		memcpy(result->getHitBoardPtr(), m_hitBoard, sizeof(m_hitBoard));
		return (result);
	};

	inline virtual void				setCell(const common::vec2 &stroke, const common::eCell &player)
	{
		if (!_isValid(stroke))
			return ;
		m_board[stroke.x][stroke.y] = player;
		_setHitBoard((const common::vec2){(uint8_t)stroke.x,(uint8_t)stroke.y}, player == common::eCell::NONE);
		_setHitBoard((const common::vec2){(uint8_t)stroke.x,(uint8_t)(stroke.y - 1)}, player != common::eCell::NONE);
		_setHitBoard((const common::vec2){(uint8_t)stroke.x,(uint8_t)(stroke.y + 1)}, player != common::eCell::NONE);
		_setHitBoard((const common::vec2){(uint8_t)(stroke.x - 1),(uint8_t)stroke.y}, player != common::eCell::NONE);
		_setHitBoard((const common::vec2){(uint8_t)(stroke.x - 1),(uint8_t)(stroke.y - 1)}, player != common::eCell::NONE);
		_setHitBoard((const common::vec2){(uint8_t)(stroke.x - 1),(uint8_t)(stroke.y + 1)}, player != common::eCell::NONE);
		_setHitBoard((const common::vec2){(uint8_t)(stroke.x + 1),(uint8_t)stroke.y}, player != common::eCell::NONE);
		_setHitBoard((const common::vec2){(uint8_t)(stroke.x + 1),(uint8_t)(stroke.y - 1)}, player != common::eCell::NONE);
		_setHitBoard((const common::vec2){(uint8_t)(stroke.x + 1),(uint8_t)(stroke.y + 1)}, player != common::eCell::NONE);
	};

	inline virtual bool				isCaptPosition(const common::vec2 &position) const
	{
		common::eCell				currentCell(m_board[position.x][position.y]);
		for (uint8_t i = 1; i < 5; ++i)
		{
			common::eCell		left1 = getCell(position, (common::eDirection)i, 1);
			common::eCell		left2 = getCell(position, (common::eDirection)i, 2);
			common::eCell		right1 = getCell(position, common::opposite((common::eDirection)i), 1);
			common::eCell		right2 = getCell(position, common::opposite((common::eDirection)i), 2);
			if ((left1 == currentCell
					&& left2 == OPPONENT(currentCell)
					&& right1 == common::eCell::NONE)
				|| (right1 == currentCell
					&& right2 == OPPONENT(currentCell)
					&& left1 == common::eCell::NONE))
				return (true);
		}
		return (false);
	};
	inline virtual bool			isCaptPosition(const common::vec2 &origin, common::eDirection dir, uint8_t dist) const
	{
		return (isCaptPosition(_convertCell(origin, dir, dist)));
	};

	inline virtual bool				getHitBoard(const common::vec2 &coord) const {return (m_hitBoard[coord.x][coord.y]);};
	inline virtual void				setCell(const common::vec2 &origin, common::eDirection dir, uint8_t dist, const common::eCell &player)
	{
		setCell(_convertCell(origin, dir, dist), player);
	};
	inline virtual common::eCell	getCell(const common::vec2 &coord) const
	{
		if (_isValid(coord))
			return (m_board[coord.x][coord.y]);
		else
			return (common::eCell::E_CELL);
	};
	inline virtual common::eCell	getCell(const common::vec2 &origin, common::eDirection dir, uint8_t dist) const
	{
		return (getCell(_convertCell(origin, dir, dist)));
	};

	inline virtual void				reset(void)
	{
		std::memset(m_board, (int)common::eCell::NONE, sizeof(m_board));
		for (uint8_t i = 0; i < N; ++i)
		{
			for (uint8_t j = 0; j < N; ++j)
			{
				if (i == N / 2 && j == N / 2)
					m_hitBoard[i][j] = true;
				else
					m_hitBoard[i][j] = false;
			}

		}
	};

	inline virtual int8_t			countAlign(const common::vec2 &stroke, const common::eDirection &dir, const common::eCell &player) const
	{
		int8_t				n(0);

		while (++n < N)
		{
			auto	cell = getCell(stroke, dir, n);
			if (cell == player)
				continue ;
			else
				return (n - 1);
		}
		return (0);
	};

	virtual int8_t			countAllAlign(const common::eCell &player) const;

	inline virtual int8_t	countAlignFree(const common::vec2 &stroke, const common::eDirection &dir, const common::eCell &player, bool permissive = true) const
	{
		int8_t				leftSide = _countAlignSide(stroke, dir, player, permissive);
		int8_t				rightSide = _countAlignSide(stroke, common::opposite(dir), player, permissive);

		if (leftSide == -1 || rightSide == -1)
			return (-1);
		return (leftSide + rightSide);
	}

private:
	common::eCell			m_board[N][N];
	bool					m_hitBoard[N][N];

	static inline bool				_isValid(const common::vec2 &stroke) {return (stroke.x >= 0 && stroke.x < N && stroke.y >= 0 && stroke.y < N);};

	virtual int8_t					_countAlignSide(const common::vec2 &stroke, const common::eDirection &dir, const common::eCell &player, bool &permissive) const;

	inline virtual common::vec2		_convertCell(const common::vec2 &origin, common::eDirection dir, uint8_t dist) const
	{
		common::vec2		dest;

		dest.x = origin.x;
		dest.y = origin.y;
		switch (dir)
		{
			case (common::eDirection::U) :
				dest.y -= dist;
				break ;
			case (common::eDirection::UR) :
				dest.y -= dist;
				dest.x += dist;
				break ;
			case (common::eDirection::R) :
				dest.x += dist;
				break ;
			case (common::eDirection::DR) :
				dest.y += dist;
				dest.x += dist;
				break ;
			case (common::eDirection::D) :
				dest.y += dist;
				break ;
			case (common::eDirection::DL) :
				dest.y += dist;
				dest.x -= dist;
				break ;
			case (common::eDirection::L) :
				dest.x -= dist;
				break ;
			case (common::eDirection::UL) :
				dest.y -= dist;
				dest.x -= dist;
				break ;
		}
		return (dest);
	}

	inline virtual void				_setHitBoard(const common::vec2 &coord, const bool val)
	{
		if (!_isValid(coord))
			return ;
		if (val == true)
			m_hitBoard[coord.x][coord.y] = true;
		else
		{
			for (int8_t i = -4; i < 5; ++i)
			{
				auto	nextCell = getCell(coord, (common::eDirection)i, 1);
				if (nextCell == common::eCell::P1 || nextCell == common::eCell::P2)
					return ;
			}
			m_hitBoard[coord.x][coord.y] = false;
		}
	};


};

#endif
