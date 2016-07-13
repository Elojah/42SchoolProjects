#include "arkanoid.h"

void		add_unit(t_window *w, int x, int y, t_unit type)
{
	unsigned int	n;

	n = (y * WIDTH_MAP + x) * 6;
	if (n > WIDTH_MAP * HEIGHT_MAP * 6 - 6)
		return ;
	w->map[n] = type;
	w->map[n + 1] = type;
	w->map[n + 2] = type;
	w->map[n + 3] = type;
	w->map[n + 4] = type;
	w->map[n + 5] = type;
}
