#include "Sorcerer.hpp"
#include "Victim.hpp"

Sorcerer::Sorcerer(std::string const &name, std::string const &title) :
	_name(std::string(name)),
	_title(std::string(title)) {
	std::cout << _name << ", " << _title << " is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src) {
	if (this != &src)
		*this = src;
	std::cout << _name << ", " << _title << " is born !" << std::endl;
}

Sorcerer::~Sorcerer(void) {
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

const std::string	&Sorcerer::getName(void) const {
	return (_name);
}

const std::string	&Sorcerer::getTitle(void) const {
	return (_title);
}

Sorcerer		&Sorcerer::operator=(Sorcerer const &rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		_title = rhs._title;
	}
	return (*this);
}

void	Sorcerer::polymorph(Victim const &v) const {
	v.getPolymorphed();
}

std::ostream&	operator<<(std::ostream& stream, Sorcerer const &s) {
	stream << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies !" << std::endl;
	return (stream);
}
