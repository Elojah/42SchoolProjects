#ifndef SORT_ITEMS_H
# define SORT_ITEMS_H

# include <string>
# include <menu.h>

class SortItems
{
public:
	SortItems(const std::string&, const std::string&);
	~SortItems(void);
	bool	operator()(const ITEM*, const ITEM*);
protected:
private:
	std::string		_upItem;
	std::string		_downItem;

	SortItems(void);
};

#endif
