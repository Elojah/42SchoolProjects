/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boot.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 10:27:00 by leeios            #+#    #+#             */
/*   Updated: 2015/07/14 13:59:52 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOT_H
# define BOOT_H

# include "Menu.hpp"
# include <string>

class Boot : public Menu
{
public:
	Boot(void);
	virtual ~Boot(void);
protected:
private:
	void		createItems(void);

/*
**Callbacks
*/
	void		newProject(ITEM *item);
	void		openProject(ITEM *item);
};

#endif
