#ifndef LOGGER_H
# define LOGGER_H

# include <string>

class Logger
{
public:
	Logger(std::string const &filename);
	~Logger(void);
	void		log(std::string const & dest, std::string const & message) const;
private:
	Logger(void);

	struct sDest {
		void			(Logger::*callback)(std::string const&) const;
		std::string		s;
	};

	std::string		_filename;
	sDest			_logDest[2];

	void			logToConsole(std::string const &log) const;
	void			logToFile(std::string const &log) const;
	std::string		makeLogEntry(std::string const &message) const;
};

#endif
