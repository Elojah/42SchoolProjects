#include "arkanoid.h"

void		key_callback(GLFWwindow *window, int key, int scancode
	, int action, int mods)
{
	static t_window		*win = 0x0;
	static int			keyValid;

	if (!win)
		win = (t_window *)glfwGetWindowUserPointer(window);
	(void)scancode;
	(void)mods;
	keyValid = (action == GLFW_PRESS || action == GLFW_REPEAT);
	if (!keyValid) {
		return ;
	}
	if (key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	} else if (key == GLFW_KEY_A) {
		move_player(win, LEFT);
	} else if (key == GLFW_KEY_D) {
		move_player(win, RIGHT);
	}
}
