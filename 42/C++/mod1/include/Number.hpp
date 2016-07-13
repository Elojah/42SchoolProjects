// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Number.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/30 16:16:59 by hdezier           #+#    #+#             //
//   Updated: 2015/04/30 16:17:50 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NUMBER_H
# define NUMBER_H

# include "AToken.hpp"

class Number: public AToken
{
public:
	Number(void);
	~Number(void);

	int				detect(const char &c);
	int				getType(void) const;
private:
	Number(Number const &rhs);

	Number			&operator=(Number const &rhs);
};

#endif
