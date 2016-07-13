#include "arkanoid.h"

static void			render_ball(t_window *w)
{
	glUseProgram(w->ball.prog_ID);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, w->ball.vertex_buffer);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glDrawArrays(
		GL_TRIANGLE_FAN,
		0,
		BALL_PRECISION + 1
	);
	glDisableVertexAttribArray(0);
}

static void			render_map(t_window *w)
{
	// return ;
	glUseProgram(w->display.prog_ID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, w->display.vertex_buffer);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glBindBuffer(GL_ARRAY_BUFFER, w->map_ID);
	glVertexAttribPointer(1, 1, GL_FLOAT, GL_TRUE, 0, BUFFER_OFFSET(0));
	glDrawArrays(
		GL_TRIANGLE_STRIP,
		0,
		WIDTH_MAP * HEIGHT_MAP * 6
	);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void				render(t_window *w)
{
	render_map(w);
	render_ball(w);
}
