// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Master.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/08/15 12:58:14 by leeios            #+#    #+#             //
//   Updated: 2015/10/29 14:06:11 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Master.hpp"
#include "Log.hpp"
#include <iostream>
#include <json/json.h>

Master::Master(void)
{
	Log::write("Init UINcurses ... ");
	_ui.init();
	_ui.setTitle("Master");
	Log::write("Init UINcurses ... DONE");
}
Master::~Master(void)
{
	delete [] _procs;
	Log::close();
}


bool				Master::readConfig(std::string const &filename)
{
	Json::Value		root;
	Json::Value		processes;
	std::ifstream	configDoc(filename.c_str(), std::ifstream::binary);
	int				i(0);

	Log::write("Read config file " + filename);
	try
	{
		configDoc >> root;
	}
	catch (std::exception &e)
	{
		configDoc.close();
		Log::write("Error reading config file !" + filename);
		_ui.notifyUser("Config file is not valid.");
		return (false);
	}
	Log::write("File syntax:\tOK");
	configDoc.close();
	processes = root["programs"];
	_nProcs = processes.size();
	_procs = new Process[_nProcs]();
	for (Json::ValueIterator ijson = processes.begin();
		 ijson != processes.end() && i < _nProcs; ++ijson)
	{
		_procs[i++].setParams(*ijson);
	}
	return (true);
}
void				Master::start(void)
{
	for (int i = 0; i < _nProcs; ++i)
	{
		_procs[i].start();
	}
}
void				Master::loop(void)
{
	for (int i = 0; i < _nProcs; ++i)
	{
		_procs[i].launch();
	}
}

std::ostream		&operator<<(std::ostream& stream, Master const &s)
{
	(void)s;
	stream << "I am master" << std::endl;
	return (stream);
}
