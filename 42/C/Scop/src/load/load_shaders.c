#include "scop.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static void			copy_shader_code(const char *filename, char *dest)
{
	int				fd;
	char			*line;
	unsigned int	i;
	unsigned int	n;

	n = 0;
	ft_exit((fd = open(filename, O_RDONLY)) < 0, "Can't read shader");
	while (get_next_line(fd, &line))
	{
		i = 0;
		while (line[i] && n < MAX_LENGTH_SHADERS - 1)
			dest[n++] = line[i++];
		dest[n++] = '\n';
		ft_memdel((void **)&line);
	}
	dest[n] = '\0';
	close(fd);
}

static void			compile_shader(GLuint shader_ID, const char *shader_code)
{
	GLint			result;
	int				info_log_length;
	char			*error_msg;

	result = GL_FALSE;
	info_log_length = 0;
	glShaderSource(shader_ID, 1, &shader_code , 0x0);
	glCompileShader(shader_ID);
	glGetShaderiv(shader_ID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shader_ID, GL_INFO_LOG_LENGTH, &info_log_length);
	error_msg = ft_memalloc(info_log_length + 1);
	glGetShaderInfoLog(shader_ID, info_log_length, 0x0, &error_msg[0]);
	error_msg[info_log_length] = '\0';
	if (info_log_length > 1) {
		write(2, "\nCompiling error:\t", 18);
		ft_putstr_fd(error_msg, 2);
	}
	ft_memdel((void **)&error_msg);
	write(1, "\n", 1);
}

static void			link_program(GLuint prog_ID
	, GLuint vertex_shader_ID, GLuint fragment_shader_ID)
{
	GLint			result;
	int				info_log_length;
	char			*error_msg;

	info_log_length = 0;
	glAttachShader(prog_ID, vertex_shader_ID);
	glAttachShader(prog_ID, fragment_shader_ID);
	glLinkProgram(prog_ID);
	glGetProgramiv(prog_ID, GL_LINK_STATUS, &result);
	glGetProgramiv(prog_ID, GL_INFO_LOG_LENGTH, &info_log_length);
	error_msg = ft_memalloc(info_log_length + 1);
	glGetProgramInfoLog(prog_ID, info_log_length, 0x0, &(error_msg[0]));
	error_msg[info_log_length] = '\0';
	if (info_log_length > 1) {
		write(2, "\nLinking error:\t", 16);
		ft_putstr_fd(error_msg, 2);
	}
	ft_memdel((void **)&error_msg);
	write(1, "\n", 1);
}

GLuint				load_shaders(const char *vertex_file_path
	, const char *fragment_file_path)
{
	GLuint	prog_ID;
	GLuint	vertex_shader_ID;
	GLuint	fragment_shader_ID;
	char	vertex_shader_code[MAX_LENGTH_SHADERS + 1];
	char	fragment_shader_code[MAX_LENGTH_SHADERS + 1];

	vertex_shader_ID = glCreateShader(GL_VERTEX_SHADER);
	fragment_shader_ID = glCreateShader(GL_FRAGMENT_SHADER);
	copy_shader_code(vertex_file_path, vertex_shader_code);
	copy_shader_code(fragment_file_path, fragment_shader_code);
	write(1, "Compiling shader:\t", 18);
	ft_putstr(vertex_file_path);
	compile_shader(vertex_shader_ID, vertex_shader_code);
	write(1, "Compiling shader:\t", 18);
	ft_putstr(fragment_file_path);
	compile_shader(fragment_shader_ID, fragment_shader_code);
	write(1, "Linking program\n", 16);
	prog_ID = glCreateProgram();
	link_program(prog_ID, vertex_shader_ID, fragment_shader_ID);
	glDeleteShader(vertex_shader_ID);
	glDeleteShader(fragment_shader_ID);
	return (prog_ID);
}
