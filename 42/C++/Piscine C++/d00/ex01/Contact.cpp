#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void) :
						_assigned(false)
{}
Contact::~Contact(void) {}

void	Contact::assignValues(void)
{
	std::cout << "Enter first name: ";
	std::cin >> _firstName;
	std::cout << "Enter last name: ";
	std::cin >> _lastName;
	std::cout << "Enter nick name: ";
	std::cin >> _nickName;
	std::cout << "Enter login: ";
	std::cin >> _login;
	std::cout << "Enter postal adress: ";
	std::cin >> _postalAddress;
	std::cout << "Enter email adress: ";
	std::cin >> _emailAddress;
	std::cout << "Enter phone number: ";
	std::cin >> _phoneNumber;
	std::cout << "Enter birthday date: ";
	std::cin >> _birthdayDate;
	std::cout << "Enter favorite meal: ";
	std::cin >> _favoriteMeal;
	std::cout << "Enter underwear color: ";
	std::cin >> _underwearColor;
	std::cout << "Enter darkest secret: ";
	std::cin >> _darkestSecret;
	_assigned = true;
}

void	Contact::displayAll(void) const
{
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nick name: " << _nickName << std::endl;
	std::cout << "Login: " << _login << std::endl;
	std::cout << "Postal adress: " << _postalAddress << std::endl;
	std::cout << "Email adress: " << _emailAddress << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Birthday date: " << _birthdayDate << std::endl;
	std::cout << "Favorite meal: " << _favoriteMeal << std::endl;
	std::cout << "Underwear color: " << _underwearColor << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;

	;
}

void	Contact::display(int index) const
{
	if (!_assigned)
		return ;
	std::cout << std::setw(10) << index << '|';
	if (_firstName.length() > 9)
		std::cout << _firstName.substr(0, 9) << '.' << '|';
	else
		std::cout << std::setw(10) << _firstName << '|';
	if (_lastName.length() > 9)
		std::cout << _lastName.substr(0, 9) << '.' << '|';
	else
		std::cout << std::setw(10) << _lastName << '|';
	if (_nickName.length() > 9)
		std::cout << _nickName.substr(0, 9) << '.';
	else
		std::cout << std::setw(9) << _nickName;
	std::cout << std::endl;
}
