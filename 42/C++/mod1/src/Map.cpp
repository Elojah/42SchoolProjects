// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/21 17:27:10 by hdezier           #+#    #+#             //
//   Updated: 2015/05/21 17:29:36 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Map.hpp"
#include "AObject.hpp"
#include "Camera.hpp"

Map::Map(void) {}
Map::~Map(void) {}

void	Map::addObject(AObject *obj)
{
	_objects.push_back(obj);
}
void	Map::draw(void) const
{
	std::vector<AObject *>::const_iterator	it;

	for (it = _objects.begin(); it != _objects.end(); ++it)
	{
		(*it)->draw();
	}
}
void	Map::refresh(Camera const &cam) const
{
	std::vector<AObject *>::const_iterator	it;

	for (it = _objects.begin(); it != _objects.end(); ++it)
	{
		(*it)->refresh(cam);
	}
}
void	Map::loop(int const key) const
{
	std::vector<AObject *>::const_iterator	it;

	for (it = _objects.begin(); it != _objects.end(); ++it)
	{
		if ((*it)->loop(key))
			break ;
	}
}
