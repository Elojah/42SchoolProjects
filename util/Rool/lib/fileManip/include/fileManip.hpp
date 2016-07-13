#ifndef FILE_MANIP_H
# define FILE_MANIP_H

# include <string>
# include <vector>
# include <map>

	typedef std::map<std::string, std::vector<std::map<std::string, std::string> > >	loopMap;
	typedef std::vector<std::string>													Strings;

	void				createArbo(std::string const&, std::string const&, std::string const&);
	void				createNewFile(std::string const&, std::string const&, std::map<std::string, std::string>&, loopMap&);
	std::string			loopTemplate(const std::string&, loopMap&);
	void				replaceMapToMap(const std::string&, const std::string&
		, std::map<std::string, std::string>&, std::map<std::string, std::string>&);
	void				addToFile(const std::string&, const std::string&, const std::string&, bool);
	std::string			searchInFile(std::string const&, std::string const&);
	std::string			getStrLine(std::string const&, std::string const&);
	std::vector<std::string>	getDirBaseName(std::string const &str);

#endif
