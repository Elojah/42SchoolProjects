// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Comment.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/30 15:48:21 by hdezier           #+#    #+#             //
//   Updated: 2015/04/30 16:16:52 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef COMMENT_H
# define COMMENT_H

# include "AToken.hpp"

class Comment: public AToken
{
public:
	Comment(void);
	~Comment(void);

	int				detect(const char &c);
	int				getType(void) const;
private:
	Comment(Comment const &rhs);

	Comment			&operator=(Comment const &rhs);
};

#endif
