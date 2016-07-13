#ifndef USUAL_CLASS_H
# define USUAL_CLASS_H

# include "TemplateBehavior.hpp"

class UsualClass : public TemplateBehavior
{
public:
	UsualClass(void);
	virtual ~UsualClass(void);
	void																		init(const std::string&, const std::string&);
	bool		isBehavior(std::string const&);
	std::string	makeBehavior(void);
protected:
	std::map<std::string, parseStr>												createMapName(void);
	loopMap																		createLoopMapName(void);
private:
};

#endif
