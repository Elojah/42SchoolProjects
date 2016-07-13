#include "arkanoid.h"
#include <math.h>

#include <stdio.h>

// static float		normalize(float x, float y, int xy)
// {
// 	float			norm;

// 	norm = sqrt(SQ(x) + SQ(y));
// 	if (xy)
// 		return (y / norm);
// 	else
// 		return (x / norm);
// }

static int		found_collide(t_window *w, int i, int x, int y)
{
	int			n;

	if ((i > BALL_PRECISION / 8 && i < BALL_PRECISION * 3 / 8)
		|| (i > BALL_PRECISION * 5 / 8 && i < BALL_PRECISION * 7 / 8))
		w->ball.dy *= -1;
	else
		w->ball.dx *= -1;
	n = (x * WIDTH_MAP + y) * 6;
	if (w->map[n] == PLAYER || w->map[n] == NONE_PIECE)
		return (1);
	if (w->map[n] > 0)
		add_unit(w, y, x, w->map[n] - 1);
	return (1);
}

static void		forward_ball(t_window *w)
{
	int			i;
	float		x;
	float		y;
	int			result;

	i = -1;
	result = 1;
	while (result)
	{
		result = 0;
		while (++i < BALL_PRECISION + 2)
		{
			if (BALL[i].x < 0 && i == BALL_PRECISION + 1)
				continue ;
			x = (int)(BALL[i].y * WIDTH_MAP);
			y = (int)(BALL[i].x * WIDTH_MAP);
			if ((w->map[(int)((x * WIDTH_MAP + y) * 6)] != EMPTY
				|| y > HEIGHT_MAP - 1 || x > WIDTH_MAP || y < 0 || x < 0)
				&& found_collide(w, i, x, y))
			{
				result = 1;
				break ;
			}
		}
		i = -1;
		while (++i < BALL_PRECISION + 2)
		{
			BALL[i].x += (w->ball.dx / SPEED);
			BALL[i].y += (w->ball.dy / SPEED);
		}
	}
}

static void		refresh_buffers(t_window *w)
{
	forward_ball(w);
	glBindBuffer(GL_ARRAY_BUFFER, w->map_ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(w->map), w->map, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, w->ball.vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(w->ball.vertex_buffer_data)
		, w->ball.vertex_buffer_data, GL_STATIC_DRAW);
}

void		loop(t_window *w)
{
	double	t;
	double	prev_t;

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	while (!glfwWindowShouldClose(w->window))
	{
		if ((t = glfwGetTime()) < prev_t + REFRESH_TIME) {
			continue ;
		}
		prev_t = t;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		render(w);
		glfwSwapBuffers(w->window);
        glfwPollEvents();
		refresh_buffers(w);
	}
}
