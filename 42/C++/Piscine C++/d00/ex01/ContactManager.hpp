#ifndef CONTACT_MANAGER_H
# define CONTACT_MANAGER_H
# define MAX_CONTACT 8

# include "Contact.hpp"
class Contact;

class ContactManager
{
public:
	ContactManager(void);
	~ContactManager(void);
	void		loop(void);
protected:
private:
	Contact			_list[MAX_CONTACT];
	unsigned int	_last;

	void		add(void);
	void		search(void);
};

#endif
