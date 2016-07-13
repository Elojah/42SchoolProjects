// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUIGL.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/27 14:59:04 by erobert           #+#    #+#             //
//   Updated: 2015/04/28 20:01:30 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GUIGL.hpp"

GUIGL::GUIGL(void):
	_window(NULL)
{
	_input[Game::PAUSE] = 'E';
	_input[Game::RESTART] = 'R';
	_input[Game::EXIT] = 'Q';
	_input[Game::UP] = 'W';
	_input[Game::LEFT] = 'A';
	_input[Game::DOWN] = 'S';
	_input[Game::RIGHT] = 'D';
	_input[Game::F1] = '1';
	_input[Game::F2] = '2';
	_input[Game::F3] = '3';
}
GUIGL::~GUIGL(void)
{
	delete _vertexBufferData;
	glDeleteBuffers(1, &_vertexBuffer);
	glDeleteVertexArrays(1, &_vertexArrayID);
	glDeleteProgram(_progID);
	glfwDestroyWindow(_window);
	glfwTerminate();
}

void				GUIGL::setKey(char c)
{
	_key = c;
}

void				GUIGL::initMap(std::vector<int> const &map,
								   int height, int width)
{
	_map = map;
	_height = height;
	_width = width;
	if (!glfwInit())
	    exit(EXIT_FAILURE);
	if (!_window)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		
		_window = glfwCreateWindow(_width * CELL_SIZE, _height * CELL_SIZE,
								   "Nibbler", NULL, NULL);
		glfwMakeContextCurrent(_window);
		glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetWindowUserPointer(_window, this);
		glfwSwapInterval(1);
		glfwSetKeyCallback(_window, keyCallback);
		glClearColor(0.1, 0.25, 0.66, 0.3);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
	}
	initBuffers();
}
void				GUIGL::updateDisplay(tNibbler const &tN, int apple,
										 int score)
{
	tNibbler::const_iterator	it(tN.begin());
	tNibbler::const_iterator	ie(tN.end());
	std::ostringstream			ss;

	ss << "Nibbler, score: " << score;
	glfwSetWindowTitle(_window,	ss.str().data());
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (it != ie)
	{
		object(it->x, it->y, Game::HEAD);
		it++;
	}
	while (it != ie)
	{
		object(it->x, it->y, Game::BODY);
		it++;
	}
	object(apple % _width, apple / _width, Game::APPLE);
	glBufferData(GL_ARRAY_BUFFER,
				 _width * _height * 6 * sizeof(sPoint),
				 _vertexBufferData, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glDrawArrays(GL_TRIANGLES, 0, _width * _height * 6);
	glDisableVertexAttribArray(0);
	glfwSwapBuffers(_window);
	glfwPollEvents();
	it = tN.begin();
	while (it != ie)
	{
		object(it->x, it->y, Game::EMPTY);
		it++;
	}
}
Game::eEvent		GUIGL::getEvent(void)
{
	int				i;

	if (_key != 0)
	{
		i = 0;
		while (i < Game::E_EVENT)
		{
			if (_input[i] == _key)
			{
				_key = 0;
				return (static_cast<Game::eEvent>(i));
			}
			i++;
		}
	}
	return (Game::E_EVENT);
}

void				GUIGL::keyCallback(GLFWwindow* window, int key,
									   int scancode, int action, int mods)
{
	static bool		keyValid;
	static GUIGL	*win;

	win  = static_cast<GUIGL *>(glfwGetWindowUserPointer(window));
	(void)scancode;
	(void)mods;
	keyValid = (action == GLFW_PRESS || action == GLFW_REPEAT);
	if (!keyValid)
		return ;
	win->setKey(key);
}
void				GUIGL::initBuffers(void)
{
	size_t			n(0);

	_vertexBufferData = new sPoint[_width * _height * 6];
	while (n < _width * _height)
	{
		object(n % _width , n / _width, static_cast<Game::eObject>(_map[n]));
		n++;
	}
	glGenVertexArrays(1, &_vertexArrayID);
	glBindVertexArray(_vertexArrayID);
	_progID = LoadShaders("./gui_gl/src/shaders/Grid.vert",
						  "./gui_gl/src/shaders/Grid.frag");
	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER,
				 _width * _height * 6 * sizeof(sPoint),
				 _vertexBufferData, GL_STATIC_DRAW);
	glUseProgram(_progID);
}
void				GUIGL::object(int x, int y, Game::eObject object)
{
	GLfloat			color(0);
	int				n((x + y * _width) * 6);
	int				tmp(CELL_SIZE / 2);
	int				i;

	x *= CELL_SIZE;
	y *= CELL_SIZE;
	if (object == Game::WALL)
		color = .5;
	else if (object == Game::BODY)
		color = .8;
	else if (object == Game::HEAD)
		color = .7;
	else if (object == Game::APPLE)
		color = .3;
	_vertexBufferData[n].color = color;
	_vertexBufferData[n].x = x - tmp;
	_vertexBufferData[n++].y = y + tmp;
	_vertexBufferData[n].color = color;
	_vertexBufferData[n].x = x + tmp;
	_vertexBufferData[n++].y = y + tmp;
	_vertexBufferData[n].color = color;
	_vertexBufferData[n].x = x + tmp;
	_vertexBufferData[n++].y = y - tmp;
	_vertexBufferData[n].color = color;
	_vertexBufferData[n].x = x + tmp;
	_vertexBufferData[n++].y = y - tmp;
	_vertexBufferData[n].color = color;
	_vertexBufferData[n].x = x - tmp;
	_vertexBufferData[n++].y = y - tmp;
	_vertexBufferData[n].color = color;
	_vertexBufferData[n].x = x - tmp;
	_vertexBufferData[n].y = y + tmp;
	for (i = 0; i < 6; ++i)
	{
		tmp = (_width + 1) * CELL_SIZE / 2;
		_vertexBufferData[n].x = _vertexBufferData[n].x - tmp + CELL_SIZE;
		_vertexBufferData[n].x /= tmp;
		tmp = (_height + 1) * CELL_SIZE / 2;
		_vertexBufferData[n].y = _vertexBufferData[n].y - tmp + CELL_SIZE;	
		_vertexBufferData[n].y /= -tmp;
		--n;
	}
}

GUIGL				*createGUI(void)
{
	return (new GUIGL);
}

void				deleteGUI(GUIGL *gN)
{
	delete gN;
}
