/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:49:43 by leeios            #+#    #+#             */
/*   Updated: 2016/05/25 15:11:04 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static void	init_result(t_result *result)
{
	int		i;
	int		j;

	i = -1;
	while (++i < MAX_PIECES * SIZE_PIECE)
	{
		j = -1;
		while (++j < MAX_PIECES * SIZE_PIECE)
			result->data[i][j] = EMPTY;
	}
	result->pieces.size = 0;
}

static void	exec(int ac, char **av)
{
	t_result			result;
	int					i;

	i = 0;
	init_result(&result);
	while (++i < ac)
		exit_with_error(file_to_pieces(&(result.pieces), av[i]));
	exit_with_error(resolve(&result));
	print_pieces(&result);
}

int			main(int ac, char **av)
{
	if (ac < 2)
		exit_with_error(NO_ARGS);
	exec(ac, av);
}
