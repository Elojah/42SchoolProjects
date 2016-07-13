// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AObject.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/30 15:32:09 by hdezier           #+#    #+#             //
//   Updated: 2015/05/22 20:43:37 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef A_OBJECT_H
# define A_OBJECT_H
# define GL_GLEXT_PROTOTYPES

# include <OpenGL/gl3.h>
# define __gl_h_
# include <glm/glm.hpp>
# include "Camera.hpp"

# define MAX_RAIN_PARTICLE 500
# define BUFFER_OFFSET(i) ((char *)NULL + (i))
# define WIDTH_MAP 400
# define HEIGHT_MAP 400

class AObject
{
public:
	AObject(void);
	virtual ~AObject(void);

	virtual void	init(void) = 0;
	virtual bool	loop(int const) = 0;
	virtual void	draw(void) const;
	virtual void	refresh(Camera const &cam);
protected:
	struct sPoint
	{
		GLfloat					x;
		GLfloat					y;
		GLfloat					z;
	};

	glm::mat4		mvp;
	GLuint			_vertexBuffer;
	GLuint			_indexBuffer;
	GLuint			_vertexArrayID;
	GLuint			_progID;
	GLuint			_matrixID;
private:
	AObject(AObject const &rhs);

	AObject			&operator=(AObject const &rhs);
};

#endif
