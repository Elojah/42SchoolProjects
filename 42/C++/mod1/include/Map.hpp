// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/21 16:56:19 by hdezier           #+#    #+#             //
//   Updated: 2015/05/21 16:57:13 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_H
# define MAP_H

# include <vector>

class AObject;
class Camera;

class Map
{
public:
	Map(void);
	~Map(void);

	void	addObject(AObject *obj);
	void	draw(void) const;
	void	refresh(Camera const &cam) const;
	void	loop(int const key) const;
private:
	std::vector<AObject *>	_objects;

	Map(Map const &rhs);

	Map		operator=(Map const &rhs);
};

#endif
