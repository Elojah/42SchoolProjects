#ifndef PARSE_STR_H
# define PARSE_STR_H

# include <string>
# include <vector>
# include <map>

std::string								parseClassName(const std::string&);
std::string								parseIncGuard(const std::string&);
std::string								parseParents(const std::string&);
std::string								parseOldName(std::string const &str);
std::string								parseNewName(std::string const &str);
std::string								parseOldName(std::string const&);
std::string								parseNewName(std::string const&);
std::vector<std::map<std::string, std::string> >					parseLoopParents(const std::string&);

#endif
