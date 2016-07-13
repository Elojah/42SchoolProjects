#ifndef CLASS_LIST_H
# define CLASS_LIST_H

# include "IModule.hpp"
# include "Menu.hpp"
# include <string>

class ClassList : public IModule, public Menu
{
public:
	ClassList(int, int, int, int);
	virtual ~ClassList(void);
	void		init(const std::string&, const std::string&);
protected:
	void		sortMenu(size_t length);
private:
	ClassList(void);
	void		createItems(void);

	/*
	**Callbacks
	*/
	void		newClass(ITEM*);
	void		newLib(ITEM*);
	void		listAttributes(ITEM*);
};

#endif
