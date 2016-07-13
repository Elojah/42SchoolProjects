#ifndef CLASS_TEMPLATE_H
# define CLASS_TEMPLATE_H

# include <string>
# include <vector>

class TemplateBehavior;

class ClassTemplate
{
public:
	ClassTemplate(const std::string&);
	~ClassTemplate(void);
	std::string						create(const std::string&);
protected:
private:
	typedef std::vector<TemplateBehavior *>	tBehaviors;
	ClassTemplate(void);

	std::string						_path;

	const static tBehaviors			_behav;
	static std::vector<TemplateBehavior *>		createBehavMap(void);
};

#endif
