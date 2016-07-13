#include "Victim.hpp"

Victim::Victim(std::string const &name) :
	_name(std::string(name)) {
	std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::Victim(Victim const &src) {
	if (this != &src)
		*this = src;
	std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::~Victim(void) {
	std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
}

const std::string	&Victim::getName(void) const {
	return (_name);
}

Victim		&Victim::operator=(Victim const &rhs) {
	if (this != &rhs) {
		_name = rhs._name;
	}
	return (*this);
}

void	Victim::getPolymorphed(void) const {
	std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream&	operator<<(std::ostream& stream, Victim const &s) {
	stream << "I'm " << s.getName() << " and I like otters !" << std::endl;
	return (stream);
}
