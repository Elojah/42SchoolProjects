// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Process.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/10/29 14:12:02 by hdezier           #+#    #+#             //
//   Updated: 2015/10/29 14:28:55 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Process.hpp"
#include "Log.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

const std::string	Process::_paramsName[19] = {
	"cmd",
	"numprocs",
	"umask",
	"workingdir",
	"autostart",
	"autorestart",
	"exitcodes",
	"startretries",
	"starttime",
	"stopsignal",
	"stoptime",
	"stdout",
	"stderr",
	"env",
	"STARTED_BY",
	"ANSWER"
};

Process::Process(void):	_pid(-1)
{}
Process::~Process(void)
{}

void				Process::start(void)
{
	launch();
}
void				Process::setParams(Json::Value &params)
{
	Json::Value							value;
	std::map<std::string, std::string>	tmp;

	Log::write("Setting process params...");
	for (int i = 0; i < 19; ++i)
	{
		value = params.get(Process::_paramsName[i], "");
		if (value.isArray())
		{
			for (Json::ValueIterator j = value.begin(); j != value.end(); ++j)
			{
				if (!(j->isArray()))
					;
			}
		}
		else
			tmp[_paramsName[i]] = value.asString();
	}
	_params.cmd = tmp["cmd"];
	_params.workingdir = tmp["workingdir"];
	_params.autostart = (tmp["autostart"] == "true");
	_params.autorestart = tmp["autorestart"];
	_params.stopsignal = tmp["stopsignal"];
	_params.stdout = tmp["stdout"];
	_params.stderr = tmp["stderr"];
	_params.env = tmp["env"];
	_params.STARTED_BY = tmp["STARTED_BY"];
	_params.ANSWER = tmp["ANSWER"];
	if (tmp.find("numprocs") != tmp.end())
		_params.numprocs = std::stoi(tmp["numprocs"]);
	if (tmp.find("umask") != tmp.end())
		_params.umask = std::stoi(tmp["umask"]);
	if (tmp.find("exitcodes") != tmp.end())
		_params.exitcodes = std::stoi(tmp["exitcodes"]);
	if (tmp.find("startretries") != tmp.end())
		_params.startretries = std::stoi(tmp["startretries"]);
	if (tmp.find("starttime") != tmp.end())
		_params.starttime = std::stoi(tmp["starttime"]);
	if (tmp.find("stoptime") != tmp.end())
		_params.stoptime = std::stoi(tmp["stoptime"]);
}

Process::eState		Process::launch(void)
{
	int				status;
	int				fdOut;
	int				fdErr;

	Log::write("Launch:_____________________________");
	if ((fdOut = open(_params.stdout.c_str(), O_WRONLY | O_APPEND)) < 0)
	{
		fdOut = 1;
		Log::write("Can't redirect stdout to " + _params.stdout);
	}
	else
		Log::write("Redirect stdout to " + _params.stdout);
	if ((fdErr = open(_params.stderr.c_str(), O_WRONLY | O_APPEND)) < 0)
	{
		fdErr = 2;
		Log::write("Can't redirect stderr to " + _params.stderr);
	}
	else
		Log::write("Redirect stderr to " + _params.stderr);
	Log::getLog() << *this;
	_pid = fork();
	if (_pid == 0)
	{
		static const char cmdName[4] = "cat";
		static const char	*fakeArgs[2] = {(char *)cmdName, nullptr};

		dup2(fdOut, 1);
		dup2(fdErr, 2);
		if (execve(_params.cmd.c_str(), (char * const *)fakeArgs, nullptr) < 0)
		{
			Log::write("Command " + _params.cmd + " can't exec.");
			close(fdErr);
			close(fdOut);
			return (PROC_ERROR);
		}
		close(fdErr);
		close(fdOut);
	}
	else
	{
		if (waitpid(_pid, &status, 0) == -1)
			Log::write("Error waiting command execution");
		if (!WIFEXITED(status))
		{
			Log::write("Command execution terminated unnormally");
			return (PROC_ERROR);
		}
		else
		{
			Log::write("Command " + _params.cmd + " executed");
			Log::write("Exit code:");
			Log::getLog() << "_____________________________"
						  << status << std::endl;
		}
	}
	return (PROC_OK);
}

void				Process::serialize(std::ostream &stream) const
{
	stream << "cmd:\t" << _params.cmd << std::endl
		   << "numprocs:\t" << _params.numprocs << std::endl
		   << "umask:\t" << _params.umask << std::endl
		   << "workingdir:\t" << _params.workingdir << std::endl
		   << "autostart:\t" << _params.autostart << std::endl
		   << "autorestart:\t" << _params.autorestart << std::endl
		   << "exitcodes:\t" << _params.exitcodes << std::endl
		   << "startretries:\t" << _params.startretries << std::endl
		   << "starttime:\t" << _params.starttime << std::endl
		   << "stopsignal:\t" << _params.stopsignal << std::endl
		   << "stoptime:\t" << _params.stoptime << std::endl
		   << "stdout:\t" << _params.stdout << std::endl
		   << "stderr:\t" << _params.stderr << std::endl
		   << "env:\t" << _params.env << std::endl
		   << "STARTED_BY:\t" << _params.STARTED_BY << std::endl
		   << "ANSWER:\t" << _params.ANSWER << std::endl;
}

std::ostream		&operator<<(std::ostream &stream, Process const &s)
{
	s.serialize(stream);
	return (stream);
}
