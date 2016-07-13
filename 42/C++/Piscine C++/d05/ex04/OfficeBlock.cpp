#include "OfficeBlock.hpp"
#include <iostream>

OfficeBlock::OfficeBlock(void) :
	_signer(NULL),
	_executer(NULL),
	_slave(NULL) {
}

OfficeBlock::OfficeBlock(Bureaucrat *sB, Bureaucrat *eB, Intern *i):
	_signer(sB),
	_executer(eB),
	_slave(i) {
}

OfficeBlock::OfficeBlock(OfficeBlock const &src) {
	if (this != &src)
		*this = src;
}

OfficeBlock::~OfficeBlock(void) {
}

OfficeBlock		&OfficeBlock::operator=(OfficeBlock const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void	OfficeBlock::setSigner(Bureaucrat *b) {
	_signer = b;
}
void	OfficeBlock::setExecutor(Bureaucrat *b) {
	_executer = b;
}
void	OfficeBlock::setIntern(Intern *i) {
	_slave = i;
}

void	OfficeBlock::doBureaucracy(std::string const &formName, std::string const &target) {
	Form	*f;

	if (!_slave || !_signer || !_executer) {
		std::cout << "Office problem: not enough staff" << std::endl;
		return ;
	}
	f = _slave->makeForm(formName, target);
	if (f == NULL)
		return ;
	try {
		f->beSigned(*_signer);
		std::cout << *f << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Office problem: can't be signed" << std::endl;
	}
	try {
		_executer->executeForm(*f);
	}
	catch (std::exception &e) {
		std::cout << "Office problem: can't be executed" << std::endl;
	}
	delete f;
}
