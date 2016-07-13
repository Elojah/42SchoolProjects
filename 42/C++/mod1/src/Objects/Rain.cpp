// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Rain.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/21 17:29:47 by hdezier           #+#    #+#             //
//   Updated: 2015/05/22 20:40:07 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Rain.hpp"
#include "LoadShaders.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

Rain::Rain(void)
{
	srand(time(0));
}
Rain::~Rain(void) {}

void					Rain::init(void)
{
	glGenVertexArrays(1, &_vertexArrayID);
	glBindVertexArray(_vertexArrayID);
	_progID = LoadShaders("./src/shaders/MVP.vert", "./src/shaders/Rain.frag");
	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertex_buffer_data), 
				 _vertex_buffer_data, GL_DYNAMIC_DRAW);
}
void					Rain::addDrop(sPoint const land[], int index, 
									  bool randHeight)
{
	size_t				position;

	(void)land;
	position = rand() % (HEIGHT_MAP * (WIDTH_MAP));
	_particle_position[index].x = position / WIDTH_MAP;
	if (!randHeight)
		_particle_position[index].y = 50;
	else
		_particle_position[index].y = rand() % 50;
	_particle_position[index].z = position % WIDTH_MAP;
	_vertex_buffer_data[index * 2].x = 0;
	_vertex_buffer_data[index * 2].y = 0;
	_vertex_buffer_data[index * 2].z = 0;
	_vertex_buffer_data[index * 2 + 1].x = 0;
	_vertex_buffer_data[index * 2 + 1].y = 0;
	_vertex_buffer_data[index * 2 + 1].z = 0;
}
void					Rain::draw(void) const
{
	glUseProgram(_progID);
	glUniformMatrix4fv(_matrixID, 1, GL_FALSE, &mvp[0][0]);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glDrawArrays(GL_LINES, 0, MAX_RAIN_PARTICLE * 2);
	glDisableVertexAttribArray(0);
}
bool					Rain::loop(int const key)
{
	(void)key;
	return (false);
}
float					Rain::downParticles(sPoint const land[], 
											float const &waterHeight)
{
	static int			downSpeed(0);
	static bool			down(false);
	static const int	around[4] = {1, -1, WIDTH_MAP, -WIDTH_MAP};
	static float		min;
	int					next;
	int					result(0);
	size_t				n;

	if (++downSpeed < DOWN_SPEED)
		return (0);
	downSpeed = 0;
	for (size_t i = 0; i < MAX_RAIN_PARTICLE; ++i)
	{
		down = false;
		_vertex_buffer_data[i * 2] = _particle_position[i];
		_particle_position[i].y -= 0.02f;
		for (size_t j = 0; j < WIDTH_MAP * HEIGHT_MAP; ++j)
		{
			if (_particle_position[i].x == land[j].x
				&& _particle_position[i].z == land[j].z
				&& _particle_position[i].y < land[j].y) 
			{
				if (_particle_position[i].y <= waterHeight)
				{
					result++;
					break ;
				}
				min = land[j].y;
				next = -1;
				for (n = 0; n < 4; ++n)
				{
					if (j + around[n] < WIDTH_MAP * HEIGHT_MAP
						&& land[j + around[n]].y < min)
					{
						min = land[j + around[n]].y;
						next = n;
					}
				}
				if (next != -1)
				{
					_particle_position[i].x = land[j + around[next]].x;
					_particle_position[i].y = land[j + around[next]].y + 0.011f;
					_particle_position[i].z = land[j + around[next]].z;
					_vertex_buffer_data[i * 2 + 1] = _particle_position[i];
					down = true;
					break ;
				}
			}
		}
		if (!down)
		{
			if (--_particle_position[i].y < 0)
				addDrop(land, i, false);
			else
				_vertex_buffer_data[i * 2 + 1] = _particle_position[i];
		}
	}
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertex_buffer_data), 
				 _vertex_buffer_data, GL_DYNAMIC_DRAW);
	return (result);
}
