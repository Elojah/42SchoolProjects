// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UINcurses.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/10/29 14:24:08 by hdezier           #+#    #+#             //
//   Updated: 2015/10/29 14:25:19 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef U_I_NCURSES_H
# define U_I_NCURSES_H

# include "AWindow.hpp"

class AWindow;

class UINcurses: public AWindow
{
public:
	UINcurses(void);
	UINcurses(int, int, int, int);
	UINcurses(UINcurses const &src);
	virtual ~UINcurses(void);

	UINcurses		&operator=(UINcurses const &rhs);

	virtual void	serialize(std::ostream &stream) const;
};

#endif
