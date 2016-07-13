/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InterfaceCmd.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 14:59:21 by leeios            #+#    #+#             */
/*   Updated: 2015/08/14 15:05:25 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_CMD_HPP
# define INTERFACE_CMD_HPP

# include "ICommand.hpp"

class InterfaceCmd : public ICommand
{
public:
	explicit InterfaceCmd(const std::string &path);
	virtual ~InterfaceCmd(void);
	virtual bool								adhere(const std::string &strCmd) const;
	virtual const std::string		exec(const std::string &strCmd) const;
protected:
private:
	std::string		_path;
};

#endif
