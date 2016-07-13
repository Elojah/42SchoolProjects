#ifndef MEMBER_TEMPLATE_H
# define MEMBER_TEMPLATE_H

# include <string>
# include <vector>

class TemplateBehavior;

class MemberTemplate
{
public:
	MemberTemplate(const std::string&);
	~MemberTemplate(void);
	std::string						create(const std::string&);
protected:
private:
	typedef std::vector<TemplateBehavior *>	tBehaviors;
	MemberTemplate(void);

	std::string						_path;

	const static tBehaviors			_behav;
	static std::vector<TemplateBehavior *>		createBehavMap(void);
};

#endif
