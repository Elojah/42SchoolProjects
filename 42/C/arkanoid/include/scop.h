#ifndef ARKANOID_H
# define ARKANOID_H

# define GL_GLEXT_PROTOTYPES
# include <OpenGL/gl3.h>
# define __gl_h_
# include <GLFW/glfw3.h>
# define GLFW_INCLUDE_GLCOREARB
# define REFRESH_TIME 0.016
# define HEIGHT_MAP 50
# define WIDTH_MAP 50
# define SIZE_CASE 20
# define BUFFER_OFFSET(i) ((char *)NULL + (i))
# define MAX_LENGTH_SHADERS 1024
# define GRID w->display.vertex_buffer_data
# define BALL w->ball.vertex_buffer_data
# define PLAYER_Y 3
# define BALL_PRECISION 20
# define SPEED 100
# define MIN(a, b) (((a) > (b) ? (b) : (a)))
# define ABS(a) (((a) > 0) ? (a) : (-a))
# define M_PI 3.14159265359
# define SQ(n) ((n) * (n))

typedef enum		e_move
{
	LEFT = -1,
	RIGHT = 1,
}					t_move;

typedef enum		e_unit
{
					PLAYER = -1,
					EMPTY = 0,
					ONE_PIECE,
					THREE_PIECE,
					NONE_PIECE
}					t_unit;

typedef struct		s_point
{
	float			x;
	float			y;
}					t_point;

typedef struct		s_brick
{
	GLuint			vertex_array_ID;
	GLuint			prog_ID;
	GLuint			vertex_buffer;
	t_point			vertex_buffer_data[HEIGHT_MAP * WIDTH_MAP * 6 + 1];
}					t_brick;

typedef struct		s_ball
{
	GLuint			prog_ID;
	GLuint			vertex_buffer;
	t_point			vertex_buffer_data[BALL_PRECISION + 3];
	float			dx;
	float			dy;
}					t_ball;

typedef struct		s_window
{
	GLFWwindow		*window;
	GLuint			map_ID;
	GLint			map[HEIGHT_MAP * WIDTH_MAP * 6 + 1];
	t_brick			display;
	t_ball			ball;
	int				player_x;
	unsigned int	current_level;
}					t_window;

/*
**Loop
*/
void				loop(t_window *w);

/*
**Rendering
*/
void				render(t_window *w);

/*
**Load map
*/
void				load_map(t_window *w, char *filename);


/*
**Key callback
*/
void				key_callback(GLFWwindow *window, int key, int scancode
	, int action, int mods);

/*
**Load shaders
*/
GLuint				load_shaders(const char *vertex_file_path
	, const char *fragment_file_path);

/*
**CRE unit
*/
void				add_unit(t_window *w, int x, int y, t_unit type);

/*
**Move player
*/
void				move_player(t_window *w, t_move t);

#endif
