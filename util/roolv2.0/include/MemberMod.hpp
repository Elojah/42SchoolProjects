/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MemberMod.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 15:24:43 by leeios            #+#    #+#             */
/*   Updated: 2015/08/14 15:28:01 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMBER_MOD_HPP
# define MEMBER_MOD_HPP

# include "Menu.hpp"
# include "IModule.hpp"

class MemberMod : public Menu, public IModule
{
public:
	MemberMod(int h, int w, int x, int y);
	virtual ~MemberMod(void);
	virtual void		construct(const std::string &path, const std::string &name);
protected:
private:
	std::string		_path;
	std::string		_name;

	void							parseLine(std::string &line, std::size_t &count);

	virtual void			sortItems(const int &length);
	virtual void			createItems(void);
};

#endif
