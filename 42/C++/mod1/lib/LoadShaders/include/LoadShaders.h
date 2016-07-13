#ifndef LOAD_SHADERS_H
# define LOAD_SHADERS_H
# define GL_GLEXT_PROTOTYPES

# include <string>
# include <fstream>
# include <vector>
# include <OpenGL/gl3.h>

GLuint LoadShaders(const char	*vertex_file_path,const char *fragment_file_path);

#endif
