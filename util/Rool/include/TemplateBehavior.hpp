#ifndef TEMPLATE_BEHAVIOR_H
# define TEMPLATE_BEHAVIOR_H

# include <string>
# include <vector>
# include <map>

class TemplateBehavior
{
public:
																			TemplateBehavior(void){};
																			virtual ~TemplateBehavior(void){};
	virtual bool															isBehavior(std::string const &str){(void)str;return (false);}
	virtual std::string														makeBehavior(void){return (std::string());}
	virtual void															init(const std::string &str, const std::string &pathSet) {
		path = pathSet;
		mapName = createMapName();
		genMapName = generateMapName(str);
		loopMapName = createLoopMapName();
	}
protected:
	typedef std::vector<std::string>										Strings;
	typedef std::string	(*parseStr)(const std::string&);
	typedef std::map<std::string, std::vector<std::map<std::string, std::string> > >	loopMap;

	std::string																path;
	std::map<std::string, parseStr>											mapName;
	loopMap																	loopMapName;
	std::map<std::string, std::string>										genMapName;

	virtual std::map<std::string, parseStr>									createMapName(void){return(std::map<std::string, parseStr>());}
	virtual loopMap															createLoopMapName(void){return(loopMap());}
	virtual std::map<std::string, std::string>								generateMapName(const std::string &str) {
		std::map<std::string, std::string>									result;

		for (std::map<std::string, parseStr>::const_iterator it = mapName.begin(); it != mapName.end(); it++) {
			result[it->first] = it->second(str);
		}
		return (result);
	}

/*
**Util functions
*/
private:
};

#endif
