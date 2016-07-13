/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StandardCmd.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 12:16:04 by leeios            #+#    #+#             */
/*   Updated: 2015/08/13 20:01:36 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STANDARD_CMD_HPP
# define STANDARD_CMD_HPP

# include "ICommand.hpp"

class StandardCmd : public ICommand
{
	public:
		explicit StandardCmd(const std::string &path);
		virtual ~StandardCmd(void);
		virtual bool								adhere(const std::string &strCmd) const;
		virtual const std::string		exec(const std::string &strCmd) const;
	protected:
	private:
		std::string	_path;
};

#endif
