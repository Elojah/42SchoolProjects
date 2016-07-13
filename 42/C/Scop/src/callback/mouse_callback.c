#include "scop.h"
#include <math.h>

void		mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	static t_window		*win = 0x0;
	static double		prev_x = W_WIDTH / 2;
	static double		prev_y = W_HEIGHT / 2;
	static float		delta_x;
	static float		delta_y;

	if (!win)
		win = (t_window *)glfwGetWindowUserPointer(window);
	delta_x = (prev_x - xpos) * MOUSE_SPEED;
	delta_y = (prev_y - ypos) * MOUSE_SPEED;
	win->cam.eye.x += delta_x * win->cam.right.x - delta_y * win->cam.up.x;
	win->cam.eye.y += delta_x * win->cam.right.y - delta_y * win->cam.up.y;
	win->cam.eye.z += delta_x * win->cam.right.z - delta_y * win->cam.up.z;
	prev_x = xpos;
	prev_y = ypos;
	refresh(win);
}
