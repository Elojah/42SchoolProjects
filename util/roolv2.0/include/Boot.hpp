/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boot.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 10:27:00 by leeios            #+#    #+#             */
/*   Updated: 2015/08/10 15:48:53 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOT_HPP
# define BOOT_HPP

# include "Menu.hpp"
# include <string>

class Boot : public Menu
{
public:
	Boot(void);
	virtual ~Boot(void);
protected:
private:
	void						createItems(void);
	virtual void		sortItems(const int &i);

/*
**Callbacks
*/
	void		newProject(ITEM *item);
	void		openProject(ITEM *item);
};

#endif
