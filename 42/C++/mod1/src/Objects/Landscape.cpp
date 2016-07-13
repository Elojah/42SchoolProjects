// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Landscape.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/30 15:42:27 by hdezier           #+#    #+#             //
//   Updated: 2015/05/23 18:09:32 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Landscape.hpp"
#include "Parser.hpp"
#include "LoadShaders.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>

Landscape::Landscape(void) {}
Landscape::Landscape(std::string const &filename):
	_filename(filename),
	_fail(false)
{
	_scenario[RAIN] = false;
	_scenario[FLOOD] = false;
	_scenario[WAVE] = false;	
}
Landscape::~Landscape(void) {}

bool								Landscape::fail(void) const
{
	return (_fail);
}
void								Landscape::init(void)
{
	Parser		p(_filename);

	_waterHeight = 0.0f;
	clearMap();
	if (p.fail())
	{
		std::cout << "Parsing:\tERROR" << std::endl;
		_fail = true;
		return ;
	}
	std::cout << "Parsing:\tDONE" << std::endl;
	lexer(p);
	std::cout << "Lexing:\t\tDONE" << std::endl;
	smoothMap();
	useMap();
	initBuffers();
	_rain.init();
	_sea.init();
	for (size_t i = 0; i < MAX_RAIN_PARTICLE; ++i)
	{
		_rain.addDrop(_vBufferData, i, true);
	}
}
void								Landscape::refresh(Camera const &cam)
{
	this->AObject::refresh(cam);
	_waterHeight += _rain.downParticles(_vBufferData, _waterHeight) / 4000.0f;
	if (_scenario[RAIN])
		_rain.refresh(cam);
	if (_scenario[FLOOD])
	{
		_sea.setHeight(_waterHeight);
		if (_scenario[WAVE])
			_sea.wave();
	}
	_sea.refresh(cam);
}
bool								Landscape::loop(int const key)
{
	switch (key)
	{
	case 69:
		_scenario[RAIN] = !_scenario[RAIN];
		_scenario[FLOOD] = true;
		break ;
	case 82:
		_scenario[FLOOD] = !_scenario[FLOOD];
		break ;
	case 84:
		_scenario[WAVE] = !_scenario[WAVE];
		_scenario[FLOOD] = true;
		break ;
	case 90:
		_waterHeight = 0.0f;
		_sea.init();
		_scenario[RAIN] = false;
		_scenario[FLOOD] = false;
		_scenario[WAVE] = false;
		break ;
	default:
		return (false);
	}
	return (true);
}

void								Landscape::lexer(const Parser &p)
{
	const std::vector<sReadToken>	reads(p.getRead());
	float							x;
	float							y;
	float							z;
	size_t							i(0);
	size_t							len;

	len = reads.size();
	while (i < len - 4) {
		if (reads[i].type != SCOPE
			|| reads[i + 1].type != NUMBER || reads[i + 2].type != NUMBER || reads[i + 3].type != NUMBER
			|| reads[i + 4].type != SCOPE)
		{
			std::cout << "Tokens are not ordered:\t" 
					  << reads[i].buffer << std::endl;
			_fail = true;
			return ;
		}
		x = strtof(reads[i + 1].buffer.c_str(), NULL);
		y = strtof(reads[i + 2].buffer.c_str(), NULL);
		z = strtof(reads[i + 3].buffer.c_str(), NULL);
		x = fmod((x / WIDTH_DIVIDE), WIDTH_MAP);
		y = fmod((y / HEIGHT_DIVIDE), HEIGHT_MAP);
		z = fmod((z / Z_DIVIDE), Z_MAX);
		std::cout << "Assign value: " << z 
				  << " at point (" << x << ", " << y << ")" << std::endl;
		_immovablePoints.push_back((sPoint){static_cast<size_t>(x), static_cast<size_t>(y), z});
		_map[static_cast<size_t>(x)][static_cast<size_t>(y)] = z;
		i += 5;
	}
}
void								Landscape::smoothMap(void)
{
	sPoint							closestPoint;
	std::vector<sPoint>::iterator	it;

	for (it = _immovablePoints.begin(); it != _immovablePoints.end(); ++it)
	{
		findClosestPoint((*it), closestPoint);
		std::cout << "Closest point from:\t" 
				  << it->x << ", " 
				  << it->y << ", " 
				  << it->z << std::endl
				  << "found at:\t\t" 
				  << closestPoint.x << ", " 
				  << closestPoint.y << ", " 
				  << closestPoint.z << std::endl;
		smoothPoint(*it, closestPoint);
		std::cout << "Fill map:\tDONE" << std::endl;
	}
}
void				Landscape::smoothPoint(sPoint const &originPoint, 
										   sPoint const &closestPoint)
{
	size_t			i;
	size_t			j;
	float			z;
	float			dist;
	float			maxDist;

	if (originPoint.z == 0.)
		return ;
	maxDist = (pow(originPoint.x > closestPoint.x ? originPoint.x - closestPoint.x : closestPoint.x - originPoint.x, 2)
			+ pow(originPoint.y > closestPoint.y ? originPoint.y - closestPoint.y : closestPoint.y - originPoint.y, 2));
	std::cout << "Dist: " << (maxDist) << std::endl;
	for (i = 0; i < WIDTH_MAP; ++i)
	{
		for (j = 0; j < HEIGHT_MAP; ++j)
		{
			dist = pow(originPoint.x > i ? originPoint.x - i : i - originPoint.x, 2) + pow(originPoint.y > j ? originPoint.y - j : j - originPoint.y, 2);
			if (dist != 0. && dist < maxDist)
			{
				z = ((sin((M_PI / 2) + sqrt(dist / maxDist) * M_PI) + 1.0f) / 2.0f) * (originPoint.z);
				if (_map[i][j] == -1.0f)
					_map[i][j] = z;
				else
					_map[i][j] += z;
			}
		}
	}
}
void				Landscape::findClosestPoint(sPoint const &origin, 
												sPoint &closest) const
{
	size_t								xDist;
	size_t								yDist;
	size_t								xTmp;
	size_t								yTmp;
	size_t								dist;
	std::vector<sPoint>::const_iterator it;

	xDist = origin.x > WIDTH_MAP / 2 ? WIDTH_MAP - origin.x : origin.x;
	yDist = origin.y > HEIGHT_MAP / 2 ? HEIGHT_MAP - origin.y : origin.y;
	if (xDist > yDist)
	{
		closest.x = origin.x;
		closest.y = origin.y > HEIGHT_MAP / 2 ? HEIGHT_MAP : 0;
		xDist = 0;
	}
	else
	{
		closest.x = origin.x > WIDTH_MAP / 2 ? WIDTH_MAP : 0;
		closest.y = origin.y;
		yDist = 0;
	}
	closest.z = 0;
	dist = xDist * xDist + yDist * yDist;
	for (it = _immovablePoints.begin(); it != _immovablePoints.end(); ++it)
	{
		xTmp = it->x > origin.x ? it->x - origin.x : origin.x - it->x;
		yTmp = it->y > origin.y ? it->y - origin.y : origin.y - it->y;
		if ((xTmp != 0 || yTmp != 0) && xTmp * xTmp + yTmp * yTmp < dist)
		{
			closest.x = it->x;
			closest.y = it->y;
			closest.z = it->z;
			dist = xTmp * xTmp + yTmp * yTmp;
		}
	}
}
void				Landscape::printMap(void) const
{
	size_t			i;
	size_t			j;

	for (i = 0; i < WIDTH_MAP; ++i)
	{
		for (j = 0; j < HEIGHT_MAP; ++j)
		{
			std::cout << _map[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}
void				Landscape::clearMap(void)
{
	size_t			i;
	size_t			j;

	for (i = 0; i < WIDTH_MAP; ++i)
	{
		for (j = 0; j < HEIGHT_MAP; ++j)
		{
			_map[i][j] = -1.0f;
		}
	}
}
void				Landscape::useMap(void)
{
	size_t			i;
	size_t			j;

	for (i = 0; i < WIDTH_MAP; ++i)
	{
		for (j = 0; j < HEIGHT_MAP; ++j)
		{
			if (_map[i][j] == -1.0f)
				_map[i][j] = 0.0f;
		}
	}
}
void				Landscape::initBuffers(void)
{
	size_t			i(0);
	size_t			n(0);

	for (i = 0; i < WIDTH_MAP * HEIGHT_MAP; ++i)
	{
		_vBufferData[i].x = i / WIDTH_MAP;
		_vBufferData[i].y = _map[i / WIDTH_MAP][i % WIDTH_MAP] * Z_MULT;
		_vBufferData[i].z = i % WIDTH_MAP;
	}
	for (i = 0; i + 1 < WIDTH_MAP * (HEIGHT_MAP - 1); ++i)
	{
		if ((i + 1) % WIDTH_MAP)
		{
			_iBufferData[n++] = i + WIDTH_MAP;
			_iBufferData[n++] = i;
			_iBufferData[n++] = i + 1;
			_iBufferData[n++] = i + 1;
			_iBufferData[n++] = i + WIDTH_MAP + 1;
			_iBufferData[n++] = i + WIDTH_MAP;
		}
	}
	glGenVertexArrays(1, &_vertexArrayID);
	glBindVertexArray(_vertexArrayID);
	_progID = LoadShaders("./src/shaders/MVP.vert", "./src/shaders/MVP.frag");
	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vBufferData),
				 _vBufferData, GL_STATIC_DRAW);
	glGenBuffers(1, &_indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_iBufferData),
				 _iBufferData, GL_STATIC_DRAW);
}
void				Landscape::draw(void) const
{
	if (_scenario[RAIN])
		_rain.draw();
	_sea.draw();
	glUseProgram(_progID);
	glUniformMatrix4fv(_matrixID, 1, GL_FALSE, &mvp[0][0]);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);
	glDrawElements(GL_TRIANGLES, (WIDTH_MAP - 1) * (HEIGHT_MAP - 1) * 6, 
				   GL_UNSIGNED_INT, BUFFER_OFFSET(0));
	glDisableVertexAttribArray(0);
}
