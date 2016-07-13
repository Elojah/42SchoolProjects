// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Rain.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/21 16:57:24 by hdezier           #+#    #+#             //
//   Updated: 2015/05/21 16:58:25 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RAIN_H
# define RAIN_H

# define DOWN_SPEED 0

# include "AObject.hpp"
class AObject;

class Rain : public AObject
{
public:
	Rain(void);
	virtual ~Rain(void);

	virtual void	init(void);
	virtual void	draw(void) const;
	virtual bool	loop(int const);
	float			downParticles(sPoint const land[], 
								  float const &waterHeight);
	void			addDrop(sPoint const land[], int index, bool randHeight);
private:
	Rain(Rain const &rhs);

	Rain			operator=(Rain const &rhs);

	sPoint			_vertex_buffer_data[(MAX_RAIN_PARTICLE * 2) + 1];
	sPoint			_particle_position[MAX_RAIN_PARTICLE + 1];
	GLfloat			_obstacleHeight[MAX_RAIN_PARTICLE + 1];
};

#endif
