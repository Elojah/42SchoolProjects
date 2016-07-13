#ifndef REPLACE_CLASS_NAME_H
# define REPLACE_CLASS_NAME_H

# include <string>
# include "TemplateBehavior.hpp"

class ReplaceClassName : public TemplateBehavior
{
public:
	ReplaceClassName(void);
	virtual ~ReplaceClassName(void);
	bool		isBehavior(std::string const&);
	std::string	makeBehavior(void);
protected:
	std::map<std::string, parseStr>	createMapName(void);
private:
};

#endif
