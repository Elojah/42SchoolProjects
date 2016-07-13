#ifndef SCOP_H
# define SCOP_H

# define GL_GLEXT_PROTOTYPES
# ifdef __APPLE__
#  include <OpenGL/gl3.h>
# else
#  include <GL/gl.h>
# endif
# define __gl_h_
# include <GLFW/glfw3.h>
# define GLFW_INCLUDE_GLCOREARB

# define REFRESH_TIME 0.016
# define BUFFER_OFFSET(i) ((char *)NULL + (i))

# define MAX_SIZE_BMP 1000000
# define MAX_LENGTH_SHADERS 1024
# define MAX_VERTEX 256
# define MAX_INDEX 1024
# define MAX_NORMAL 1024
# define MAX_TEX 1024

# define W_WIDTH 1200
# define W_HEIGHT 900

# define VIEW_NEAR 0.001f
# define VIEW_FAR 500.0f
# define VIEW_FOV 45.0f
# define VIEW_ASPECT (4.0f / 3.0f)

# define M_PI 3.14159265359
# define RAD(n) ((n) * M_PI / 180.0f)
# define MIN(a, b) (((a) > (b) ? (b) : (a)))
# define ABS(a) (((a) > 0) ? (a) : -(a))
# define SQ(n) ((n) * (n))

# define MOVE_SPEED 0.5
# define MOUSE_SPEED 0.01
# define ROTATE_DIST 20

typedef enum		e_move
{
	LEFT = 0,
	RIGHT,
	UP,
	DOWN,
	FORWARD,
	BACK
}					t_move;

typedef struct		s_coord
{
	GLfloat			u;
	GLfloat			v;
}					t_coord;

typedef struct		s_point
{
	GLfloat			x;
	GLfloat			y;
	GLfloat			z;
}					t_point;

typedef struct		s_bmp
{
	unsigned int	data_pos;
	unsigned int	width;
	unsigned int	height;
	unsigned int	size;
	unsigned char	data[MAX_SIZE_BMP + 1];
}					t_bmp;

typedef struct		s_camera
{
	t_point			center;
	t_point			eye;
	t_point			up;
	t_point			forward;
	t_point			right;
	GLfloat			view[4][4];
	GLfloat			proj[4][4];
	GLfloat			***vp;
	GLuint			mvp_id;
}					t_camera;

typedef struct		s_object
{
	unsigned char	name[64];
	GLuint			vertex_array_id;
	t_point			center;
	t_bmp			bmp;

	GLuint			ve_index_buffer;
	GLuint			ve_index_buffer_data[(MAX_INDEX + 1) * 3];
	GLuint			te_index_buffer;
	GLuint			te_index_buffer_data[(MAX_INDEX + 1) * 3];
	GLuint			no_index_buffer;
	GLuint			no_index_buffer_data[(MAX_INDEX + 1) * 3];
	unsigned int	index_buffer_size;

	GLuint			vertex_buffer;
	t_point			vertex_buffer_data[MAX_VERTEX + 1];
	unsigned int	vertex_buffer_size;

	GLuint			normal_buffer;
	t_point			normal_buffer_data[MAX_NORMAL + 1];
	unsigned int	normal_buffer_size;

	GLuint			tex_id;
	GLuint			tex_buffer;
	t_coord			tex_buffer_data[MAX_TEX + 1];
	unsigned int	tex_buffer_size;
}					t_object;

typedef struct		s_window
{
	GLFWwindow		*window;
	GLuint			prog_id;
	t_object		obj;
	t_camera		cam;
}					t_window;

/*
**INIT FCT
*/
void				load_obj(t_object *obj, char *filename);
void				load_bmp(t_object *obj, char *filename);
void				init_camera(t_camera *cam);
void				loop(t_window *w);

/*
**RUNNING FCT
*/
void				refresh(t_window *w);
void				render(t_window *w);

/*
**Callbacks
*/
void				key_callback(GLFWwindow *window, int key, int scancode
	, int action, int mods);
void				mouse_callback(GLFWwindow* window
	, double xpos, double ypos);

/*
**Load shaders
*/
GLuint				load_shaders(const char *vertex_file_path
	, const char *fragment_file_path);

#endif
