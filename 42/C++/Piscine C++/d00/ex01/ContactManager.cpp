#include "ContactManager.hpp"
#include "Contact.hpp"
#include <iostream>

ContactManager::ContactManager(void) :
										_last(0)
{}
ContactManager::~ContactManager(void) {}

void	ContactManager::loop(void)
{
	std::string		input;

	while (1)
	{
		std::cout << "$>";
		std::cin >> input;
		if (!input.compare("EXIT"))
			break ;
		else if (!input.compare("ADD"))
			add();
		else if (!input.compare("SEARCH"))
			search();
		else
			std::cout << input << std::endl;
	}
}

void	ContactManager::add(void)
{
	if (_last >= MAX_CONTACT)
		std::cout << "Already 8 contacts created. Too bad." << std::endl;
	else
		_list[_last++].assignValues();
}

void	ContactManager::search(void)
{
	unsigned int	i;
	unsigned int	n;

	if (_last == 0)
		return ;
	for (i = 0; i < MAX_CONTACT; ++i)
		_list[i].display(i);
	do
	{
		std::cout << "Get more info for index: ";
		std::cin >> n;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	} while (n >= _last);
	_list[n].displayAll();
}
