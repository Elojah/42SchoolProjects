// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Camera.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/30 15:44:28 by hdezier           #+#    #+#             //
//   Updated: 2015/05/21 17:25:17 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CAMERA_H
# define CAMERA_H
# define GL_GLEXT_PROTOTYPES

# define FOV 45.0f
# define RATIO 4.0f / 3.0f
# define ZNEAR 0.1f
# define ZFAR 500.0f
# define SPEED 3.0f
# define M_SPEED 0.005f

# include <OpenGL/gl3.h>
# include <glm/glm.hpp>

enum eDirection
{
	CONSTANT = 0,
	RIGHT = 1,
	LEFT = 2,
	UP = 3,
	DOWN = 4
};

class Camera
{
public:
	Camera(void);
	~Camera(void);

	glm::mat4 const		&getViewProj(void) const;
	void				setSize(const size_t &width, const size_t &height);
	void				moveEye(const int &xpos, const int &ypos);
	void				moveForward(void);
	void				moveBackward(void);
	void				moveUp(void);
	void				moveDown(void);
	void				strafeRight(void);
	void				strafeLeft(void);
private:
	Camera(Camera const &rhs);

	Camera			&operator=(Camera const &rhs);

	void			calculus(void);
	std::size_t		_width;
	std::size_t		_height;
	glm::mat4		_view;
	glm::mat4		_projection;
	glm::mat4		_vp;
	glm::vec3		_direction;
	glm::vec3		_position;
	glm::vec3		_up;
};

#endif
