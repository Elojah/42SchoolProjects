/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_polynomials.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 14:12:09 by erobert           #+#    #+#             */
/*   Updated: 2014/03/26 12:45:51 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytracer.h"

static void			ft_solve_quadratic(double a, double b, double c, double *x)
{
	double			delta;

	delta = b * b - 4 * a * c;
	if (delta < 0.0)
		return ;
	delta = sqrt(delta);
	x[0] = (-b - delta) / (2 * a);
	x[1] = (-b + delta) / (2 * a);
}

static void			ft_solve_cubic(double *a, double *x)
{
	double			tmp[3];
	double			q;
	double			r;

	tmp[0] = a[2] / a[3];
	tmp[1] = a[1] / a[3];
	tmp[2] = a[0] / a[3];
	q = (pow(tmp[0], 2) - 3 * tmp[1]) / 9;
	r = (2 * pow(tmp[0], 3) - 9 * tmp[0] * tmp[1] + 27 * tmp[2]) / 54;
	tmp[1] = pow(q, 3) - r * r;
	if (tmp[1] < 0.0)
	{
		x[0] = pow(sqrt(-tmp[1]) + fabs(r), 1.0 / 3.0);
		x[0] = -(r / fabs(r)) * (x[0] + q / x[0]) - tmp[0] / 3.0;
	}
	else
	{
		if (q < 0.0)
			return ;
		tmp[2] = acos(r / sqrt(pow(q, 3)));
		x[0] = -2.0 * sqrt(q) * cos(tmp[2] / 3.0) - tmp[0] / 3.0;
		x[1] = -2 * sqrt(q) * cos((tmp[2] + 2 * M_PI) / 3.0) - tmp[0] / 3.0;
		x[2] = -2 * sqrt(q) * cos((tmp[2] + 4 * M_PI) / 3.0) - tmp[0] / 3.0;
	}
}

static double		ft_step_quartic(double *tmp1, double *tmp2, double *y)
{
	double			r;
	double			rrev;

	tmp2[3] = 1.0;
	ft_solve_cubic(tmp2, y);
	y[0] = fmax(y[0], fmax(y[1], y[2]));
	r = 0.25 * pow(tmp1[3], 2) - tmp1[2] + y[0];
	if (r < 0.0)
		r = 0.0;
	r = sqrt(r);
	if (r < EPSILON)
	{
		tmp2[2] = y[0] * y[0] - 4.0 * tmp1[0];
		tmp2[0] = .75 * tmp1[3] * tmp1[3] - 2 * tmp1[2] + 2 * sqrt(tmp2[2]);
		tmp2[1] = .75 * tmp1[3] * tmp1[3] - 2 * tmp1[2] - 2 * sqrt(tmp2[2]);
	}
	else
	{
		rrev = 1.0 / r;
		tmp2[2] = .75 * pow(tmp1[3], 2) - pow(r, 2.0) - 2.0 * tmp1[2];
		tmp2[3] = 4.0 * tmp1[3] * tmp1[2] - 8.0 * tmp1[1] - pow(tmp1[3], 3);
		tmp2[0] = tmp2[2] + .25 * rrev * tmp2[3];
		tmp2[1] = tmp2[2] - .25 * rrev * tmp2[3];
	}
	return (r);
}

static void			ft_solve_quartic(double *a, double *x, double *y)
{
	double			tmp1[4];
	double			tmp2[4];
	double			r;

	tmp1[0] = a[0] / a[4];
	tmp1[1] = a[1] / a[4];
	tmp1[2] = a[2] / a[4];
	tmp1[3] = a[3] / a[4];
	tmp2[0] = 4.0 * tmp1[2] * tmp1[0] - pow(tmp1[1], 2);
	tmp2[0] -= pow(tmp1[3], 2) * tmp1[0];
	tmp2[1] = tmp1[1] * tmp1[3] - 4.0 * tmp1[0];
	tmp2[2] = -tmp1[2];
	r = ft_step_quartic(tmp1, tmp2, y);
	if (tmp2[0] > 0.0)
	{
		tmp2[0] = sqrt(tmp2[0]) * .5;
		x[0] = -.25 * tmp1[3] + .5 * r + tmp2[0];
		x[1] = -.25 * tmp1[3] + .5 * r - tmp2[0];
	}
	if (tmp2[1] > 0.0)
	{
		tmp2[1] = sqrt(tmp2[1]) * .5;
		x[2] = -.25 * tmp1[3] - .5 * r + tmp2[1];
		x[3] = -.25 * tmp1[3] - .5 * r - tmp2[1];
	}
}

void				ft_solve_polynomials(double *a, double *x)
{
	double			y[3];

	if (fabs(a[4]) > EPSILON)
	{
		y[0] = -1138.42;
		y[1] = -1138.42;
		y[2] = -1138.42;
		ft_solve_quartic(a, x, y);
	}
	else if (fabs(a[3]) > EPSILON)
		ft_solve_cubic(a, x);
	else if (fabs(a[2]) > EPSILON)
		ft_solve_quadratic(a[2], a[1], a[0], x);
	else if (fabs(a[1]) < EPSILON)
		x[0] = -1;
	else
		x[0] = -a[0] / a[1];
}
