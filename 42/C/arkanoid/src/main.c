#include "arkanoid.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void		init_buffer(t_window *w)
{
	int					i;
	unsigned int		n;

	i = -1;
	while (++i < WIDTH_MAP * (HEIGHT_MAP - 1))
	{
		if ((i + 1) % WIDTH_MAP == 0)
			continue ;
		n = i * 6;
		GRID[n].x = (float)(i % WIDTH_MAP) / WIDTH_MAP;
		GRID[n].y = (float)(i / WIDTH_MAP) / HEIGHT_MAP;
		GRID[n + 1].x = (float)((i + 1) % WIDTH_MAP) / WIDTH_MAP;
		GRID[n + 1].y = (float)((i + 1) / WIDTH_MAP) / HEIGHT_MAP;
		GRID[n + 2].x = (float)((i + WIDTH_MAP) % WIDTH_MAP) / WIDTH_MAP;
		GRID[n + 2].y = (float)((i + WIDTH_MAP) / WIDTH_MAP) / HEIGHT_MAP;
		GRID[n + 3].x = (float)((i + 1) % WIDTH_MAP) / WIDTH_MAP;
		GRID[n + 3].y = (float)((i + 1) / WIDTH_MAP) / HEIGHT_MAP;
		GRID[n + 4].x = (float)((i + WIDTH_MAP) % WIDTH_MAP) / WIDTH_MAP;
		GRID[n + 4].y = (float)((i + WIDTH_MAP) / WIDTH_MAP) / HEIGHT_MAP;
		GRID[n + 5].x = (float)((i + WIDTH_MAP + 1) % WIDTH_MAP) / WIDTH_MAP;
		GRID[n + 5].y = (float)((i + WIDTH_MAP + 1) / WIDTH_MAP) / HEIGHT_MAP;
	}
}

static void		init_gl(t_window *w)
{
	init_buffer(w);
	glGenVertexArrays(3, &w->display.vertex_array_ID);
	glBindVertexArray(w->display.vertex_array_ID);
	w->display.prog_ID = load_shaders("./src/shaders/Grid.vert"
									, "./src/shaders/Grid.frag");
	w->ball.prog_ID = load_shaders("./src/shaders/Ball.vert"
									, "./src/shaders/Ball.frag");
	glGenBuffers(1, &w->ball.vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, w->ball.vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(w->ball.vertex_buffer_data)
		, w->ball.vertex_buffer_data, GL_STATIC_DRAW);
	glGenBuffers(1, &w->map_ID);
	glBindBuffer(GL_ARRAY_BUFFER, w->map_ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(w->map), w->map, GL_STATIC_DRAW);
	glGenBuffers(1, &w->display.vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, w->display.vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(w->display.vertex_buffer_data)
		, w->display.vertex_buffer_data, GL_STATIC_DRAW);
}

static void		init_window(t_window *w)
{
	ft_exit(!glfwInit(), "init glfw");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	w->window = glfwCreateWindow(WIDTH_MAP * SIZE_CASE, HEIGHT_MAP * SIZE_CASE
		, "--ARKANOID--", NULL, NULL);
	glfwMakeContextCurrent(w->window);
	glfwSetWindowUserPointer(w->window, w);
	glfwSetInputMode(w->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSwapInterval(1);
	glfwSetKeyCallback(w->window, key_callback);
	glClearColor(0, 0, 0, 0);
}

static void		destroy_window(t_window *w)
{
	glDeleteBuffers(1, &w->display.vertex_buffer);
	glDeleteBuffers(1, &w->ball.prog_ID);
	glDeleteBuffers(1, &w->map_ID);
	glDeleteVertexArrays(1, &w->display.vertex_array_ID);
	glDeleteProgram(w->display.prog_ID);

	glfwDestroyWindow(w->window);
	glfwTerminate();
	write(1, "Credits:\n\thdezier\n\tdrabahi\n@42SchoolProject\n", 44);
}

int			main(int ac, char **av)
{
	t_window	w;

	ft_exit(ac != 2, "Usage:\t./arkanoid [filename]");
	load_map(&w, av[1]);
	init_window(&w);
	init_gl(&w);
	loop(&w);
	destroy_window(&w);
	return (0);
}
