#include "scop.h"
#include <math.h>

static void	move_point(t_point *p, t_point *dir, float n)
{
	p->x += dir->x * n * MOVE_SPEED;
	p->y += dir->y * n * MOVE_SPEED;
	p->z += dir->z * n * MOVE_SPEED;
}

static void	rotate_camera(t_window *w, int n)
{
	static int	angle = 0;

	angle = (angle + n) % 360;
	w->cam.center.x = cos(RAD(angle)) * ROTATE_DIST + w->obj.center.x;
	w->cam.center.y = sin(RAD(angle)) * ROTATE_DIST + w->obj.center.y;
	w->cam.center.z = w->obj.center.z;
	refresh(w);
}

static void	move_camera(t_window *w, t_move t)
{
	if (t == LEFT)
	{
		move_point(&(w->cam.center), &(w->cam.right), -1);
		move_point(&(w->cam.eye), &(w->cam.right), -1);
	}
	else if (t == RIGHT)
	{
		move_point(&(w->cam.center), &(w->cam.right), 1);
		move_point(&(w->cam.eye), &(w->cam.right), 1);
	}
	else if (t == FORWARD)
	{
		move_point(&(w->cam.center), &(w->cam.forward), 1);
		move_point(&(w->cam.eye), &(w->cam.forward), 1);
	}
	else if (t == BACK)
	{
		move_point(&(w->cam.center), &(w->cam.forward), -1);
		move_point(&(w->cam.eye), &(w->cam.forward), -1);
	}
	else if (t == UP)
	{
		move_point(&(w->cam.center), &(w->cam.up), 1);
		move_point(&(w->cam.eye), &(w->cam.up), 1);
	}
	else if (t == DOWN)
	{
		move_point(&(w->cam.center), &(w->cam.up), -1);
		move_point(&(w->cam.eye), &(w->cam.up), -1);
	}
	else
		return ;
	refresh(w);
}

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
	if (key == GLFW_KEY_ESCAPE) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	} else if (key == GLFW_KEY_A) {
		move_camera(win, LEFT);
	} else if (key == GLFW_KEY_D) {
		move_camera(win, RIGHT);
	} else if (key == GLFW_KEY_W) {
		move_camera(win, FORWARD);
	} else if (key == GLFW_KEY_S) {
		move_camera(win, BACK);
	} else if (key == GLFW_KEY_SPACE) {
		move_camera(win, UP);
	} else if (key == GLFW_KEY_C) {
		move_camera(win, DOWN);
	} else if (key == GLFW_KEY_Q) {
		rotate_camera(win, -1);
	} else if (key == GLFW_KEY_E) {
		rotate_camera(win, 1);
	}
}
