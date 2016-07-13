/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IModule.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 17:40:31 by leeios            #+#    #+#             */
/*   Updated: 2015/08/14 19:39:51 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MODULE_HPP
# define I_MODULE_HPP

# include <string>

class IModule
{
public:
	virtual ~IModule(void) {}
	virtual void		construct(const std::string &path, const std::string &name) = 0;
};

#endif
