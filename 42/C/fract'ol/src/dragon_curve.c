/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon_curve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 17:29:06 by hdezier           #+#    #+#             */
/*   Updated: 2015/01/15 17:29:07 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>

static void	add_dragon_string(t_map *m, char c, char **res)
{
	char	*tmp;
	char	*evolve;

	if (c == 'X')
		evolve = m->dd.x_rule;
	else if (c == 'Y')
		evolve = m->dd.y_rule;
	else
	{
		evolve = ft_strnew(2);
		evolve[0] = c;
	}
	tmp = *res;
	*res = ft_strjoin(tmp, evolve);
	ft_memdel((void **)&tmp);
	if (c != 'X' && c != 'Y')
		ft_memdel((void **)&evolve);
}

static void	dragon_evolution(t_map *m)
{
	int		i;
	int		len;
	char	*res;

	i = -1;
	len = (int)ft_strlen(m->dd.s);
	res = ft_strnew(1);
	while (++i < len)
		add_dragon_string(m, m->dd.s[i], &res);
	ft_memdel((void **)&(m->dd.s));
	m->dd.s = res;
}

static int	color_dragon(int i[2])
{
	float	ratio;
	int		color;

	ratio = (float)i[0] / (float)i[1];
	color = 0;
	color += ADD_R(255.0 * ratio);
	color += ADD_G(255.0 * ratio);
	color += ADD_B(255.0 * ratio);
	return (color);
}

static void	interpret_dragon(t_map *m, int dirs[4][2])
{
	int		di;
	int		i[2];
	int		xy[2];
	int		tmp[2];

	di = 1;
	i[0] = -1;
	i[1] = ft_strlen(m->dd.s);
	xy[0] = m->move[0] + WIN_W / 2;
	xy[1] = m->move[1] + WIN_H / 2;
	while (++i[0] < i[1])
	{
		if (m->dd.s[i[0]] == '+')
			di = (di + 1) % 4;
		else if (m->dd.s[i[0]] == '-')
			di = (di + 3) % 4;
		else if (m->dd.s[i[0]] == 'F')
		{
			draw_line(m, (t_point){xy[0], xy[1], color_dragon(i)}
				, (t_point){(tmp[0] = xy[0] + m->zoom * dirs[di][0])
				, (tmp[1] = xy[1] + m->zoom * dirs[di][1]), color_dragon(i)});
			xy[0] = tmp[0];
			xy[1] = tmp[1];
		}
	}
}

void		dragon_curve(t_map *m)
{
	static	int	dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	int			i;

	i = -1;
	m->zoom = 5;
	m->dd.s = ft_strdup("FX");
	while (++i < m->dd.depth)
		dragon_evolution(m);
	interpret_dragon(m, dirs);
	ft_memdel((void **)&(m->dd.s));
}
