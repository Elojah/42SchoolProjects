/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICommand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 11:47:36 by leeios            #+#    #+#             */
/*   Updated: 2015/08/13 20:00:15 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_COMMAND_HPP
# define I_COMMAND_HPP

# include <string>

class ICommand
{
	public:
		virtual ~ICommand(void) {}
		virtual bool								adhere(const std::string &strCmd) const = 0;
		virtual const std::string		exec(const std::string &strCmd) const = 0;
	protected:
	private:
};

#endif
