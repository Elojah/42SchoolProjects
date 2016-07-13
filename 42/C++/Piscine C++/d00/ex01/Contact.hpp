#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact
{
public:
	Contact(void);
	~Contact(void);
	void	assignValues(void);
	void	display(int index) const;
	void	displayAll(void) const;
protected:
private:
	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickName;
	std::string		_login;
	std::string		_postalAddress;
	std::string		_emailAddress;
	std::string		_phoneNumber;
	std::string		_birthdayDate;
	std::string		_favoriteMeal;
	std::string		_underwearColor;
	std::string		_darkestSecret;
	bool			_assigned;
};

#endif
