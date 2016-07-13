// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sea.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/21 16:59:28 by hdezier           #+#    #+#             //
//   Updated: 2015/05/21 17:00:19 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SEA_H
# define SEA_H

# define START_FLOOD -5.0f

# include "AObject.hpp"

class Sea : public AObject
{
public:
	Sea(void);
	virtual ~Sea(void);

	virtual void	init(void);
	virtual void	draw(void) const;
	virtual bool	loop(int const);
	void			wave(void);
	void			setHeight(float waterHeight);
private:
	Sea(Sea const &rhs);

	Sea				operator=(Sea const &rhs);

	sPoint			_vertex_buffer_data[8];
};

#endif
