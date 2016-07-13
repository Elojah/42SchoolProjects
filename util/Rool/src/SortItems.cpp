#include "SortItems.hpp"

SortItems::SortItems(const std::string &up, const std::string &down) {
	_upItem = std::string(up);
	_downItem = std::string(down);
}

SortItems::~SortItems(void) {
}

bool	SortItems::operator()(const ITEM *lhs, const ITEM *rhs) {
	if (!lhs || !rhs) {
		return (false);
	}
	std::string	lstr(item_name(lhs));
	std::string	rstr(item_name(rhs));

	if (lstr.compare(_downItem) == 0 || rstr.compare(_upItem) == 0) {
		return (false);
	} else if (lstr.compare(_upItem) == 0 || rstr.compare(_downItem) == 0) {
		return (true);
	}
	return (lstr.compare(rstr) < 0);
}
