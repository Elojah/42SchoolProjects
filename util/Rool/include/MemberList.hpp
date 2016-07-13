#ifndef MEMBER_LIST_H
# define MEMBER_LIST_H

# include <string>
# include "Menu.hpp"
# include "IModule.hpp"

class MemberList : public IModule, public Menu
{
public:
	MemberList(int, int, int, int);
	virtual ~MemberList(void);
	void		init(const std::string&, const std::string&);
protected:
	void		sortMenu(size_t length);
private:
	std::string		_path;
	std::string		_name;

	MemberList(void);

	void		createItems(void);
	void		newMember(ITEM *);
	void		renameClass(ITEM *);

	void		parseLine(std::string&, std::size_t&);
};

#endif
