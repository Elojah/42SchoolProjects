// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scope.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/21 16:58:40 by hdezier           #+#    #+#             //
//   Updated: 2015/05/21 17:00:51 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCOPE_H
# define SCOPE_H

# include "AToken.hpp"

class Scope: public AToken
{
public:
	Scope(void);
	~Scope(void);

	int				detect(const char &c);
	int				getType(void) const;
private:
	Scope(Scope const &rhs);

	Scope			operator=(Scope const &rhs);
};

#endif
