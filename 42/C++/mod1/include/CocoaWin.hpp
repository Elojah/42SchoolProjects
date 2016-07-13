// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CocoaWin.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/30 15:46:20 by hdezier           #+#    #+#             //
//   Updated: 2015/05/21 17:22:14 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef COCOA_WIN_H
# define COCOA_WIN_H
# define GL_GLEXT_PROTOTYPES

# include <vector>
# include <string>
# include <OpenGL/gl3.h>
# define __gl_h_
# include <GLFW/glfw3.h>
# define GLFW_INCLUDE_GLCOREARB

# include "Camera.hpp"
class Camera;
class AObject;
class Map;

class CocoaWin
{
public:
	CocoaWin(std::size_t, std::size_t);
	~CocoaWin(void);

	void				init(void);
	void				loop(Map const &map, Camera &cam);
	Map const			*getMap(void) const;
	Camera				*getCam(void) const;
private:
	GLFWwindow			*_window;
	std::size_t			_width;
	std::size_t			_height;
	const Map			*_map;
	Camera				*_cam;

	CocoaWin(void);
	CocoaWin(CocoaWin const &rhs);

	CocoaWin			&operator=(CocoaWin const &rhs);

	static void	keyCallback(GLFWwindow* window, int key, int scancode, 
							int action, int mods);
	static void	cursorPositionCallback(GLFWwindow* window, double xpos, 
									   double ypos);
};

#endif
