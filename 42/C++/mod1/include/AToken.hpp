// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AToken.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/30 15:51:00 by hdezier           #+#    #+#             //
//   Updated: 2015/04/30 16:04:24 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef A_TOKEN_H
# define A_TOKEN_H

# include <string>
# include <set>
# include <ctype.h>
# include <iostream>

struct sReadToken
{
	std::string		buffer;
	int				type;
};

enum
{
	NONE = 0,
	FOUND,
	COMPLETE,
	MASTER
};
enum
{
	NO_VALID = 0,
	NUMBER,
	SCOPE,
	COMMENT
};

class AToken
{
public:
	AToken(void);
	virtual ~AToken(void);

	typedef std::set<std::string>		tSymbols;

	virtual int				detect(const char &c) = 0;
	virtual int				getType(void) const = 0;
	void					reset(void);
	sReadToken				getAsRead(void) const;
	bool					isEmptyWord(void) const;
	void					display(void) const;
protected:
	std::string				_buffer;
private:
	AToken(AToken const &rhs);

	AToken					&operator=(AToken const &rhs);
};

#endif
