#include "arkanoid.h"

void		move_player(t_window *w, t_move t)
{
	if ((t == LEFT && w->player_x < 2)
		|| (t == RIGHT && w->player_x == WIDTH_MAP - 3))
		return ;
	add_unit(w, w->player_x - (t * 2), PLAYER_Y, EMPTY);
	add_unit(w, w->player_x + (t * 2), PLAYER_Y, PLAYER);
	w->player_x += t;
}
