// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Log.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/08/15 13:01:29 by leeios            #+#    #+#             //
//   Updated: 2015/10/29 14:11:52 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Log.hpp"

const char		Log::logFile[15] = "./util/log.txt";
std::ofstream	Log::_log(Log::logFile);

Log::Log(void)
{}
Log::~Log(void)
{}

void			Log::close(void)
{
	Log::_log.close();
}
std::ofstream	&Log::getLog(void)
{
	return (Log::_log);
}
void			Log::write(const std::string &msg)
{
	Log::_log << msg << std::endl;
}
