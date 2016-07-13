/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:49:01 by leeios            #+#    #+#             */
/*   Updated: 2016/05/25 15:19:55 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_H
# define TETRIS_H

# define SIZE_PIECE 4
# define MAX_PIECES 26

typedef enum		e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;

typedef enum		e_bloc
{
	DEAD = 0,
	ALIVE,
}					t_bloc;

typedef enum		e_piece_value
{
	EMPTY = -1,
	BLOC = -2
}					t_piece_value;

typedef struct		s_piece
{
	t_piece_value	data[SIZE_PIECE][SIZE_PIECE];
}					t_piece;

typedef struct		s_array_piece
{
	t_piece			data[MAX_PIECES];
	int				size;
}					t_array_piece;

typedef struct		s_result
{
	int				data[MAX_PIECES * SIZE_PIECE][MAX_PIECES * SIZE_PIECE];
	t_bloc			check_data[MAX_PIECES * SIZE_PIECE]
	[MAX_PIECES * SIZE_PIECE];
	t_array_piece	pieces;
	int				fit_size;
	int				current_piece;
}					t_result;

typedef enum		e_error
{
	NONE = 0,
	NO_ARGS,
	READING_ERROR,
	UNKNOWN_CHAR,
	BAD_SEPARATION,
	NO_FOUR_IN_A_ROW,
	NO_DISPOSITION_FOUND,
	NO_DISPOSITION_FOUND_AT_SIZE,
	SIZE_ENUM_ERROR
}					t_error;

/*
** Error handling
*/
void				exit_with_error(t_error err_value);

/*
** Parsing
*/
t_error				file_to_pieces(t_array_piece *array, char *file_name);

/*
** Resolution
*/
t_error				resolve(t_result *result);
t_error				fill_result_in_size(t_result *result);
int					calculus_dead_blocks(t_result *result);

/*
** Display
*/
void				print_pieces(t_result *result);

#endif
