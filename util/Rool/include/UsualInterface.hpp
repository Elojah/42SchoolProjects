#ifndef USUAL_INTERFACE_H
# define USUAL_INTERFACE_H

# include "TemplateBehavior.hpp"

class UsualInterface : public TemplateBehavior
{
public:
	UsualInterface(void);
	virtual ~UsualInterface(void);
	bool		isBehavior(std::string const&);
	std::string	makeBehavior(void);
protected:
	std::map<std::string, parseStr>											createMapName(void);
	loopMap																	createLoopMapName(void);
private:
};

#endif
