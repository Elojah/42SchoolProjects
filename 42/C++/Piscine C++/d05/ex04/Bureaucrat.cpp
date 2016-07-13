#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const &s, int const grade) :
	_name(s),
	_grade(grade) {
	if (_grade < 1) {
		throw GradeTooHighException();
	} else if (_grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	if (this != &src)
		*this = src;
}

Bureaucrat::~Bureaucrat(void) {
}

Bureaucrat		&Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		_grade = rhs._grade;
	}
	return (*this);
}

Bureaucrat			&Bureaucrat::operator++(void) {
	if (_grade < 2)
		throw GradeTooHighException();
	else
		_grade--;
	return (*this);
}
Bureaucrat			&Bureaucrat::operator--(void) {
	if (_grade > 149)
		throw GradeTooLowException();
	else
		_grade++;
	return (*this);
}

void				Bureaucrat::executeForm(Form const &f) const {
	try {
		f.execute(*this);
		std::cout << _name << " executes "
				<< f.getName() << "." << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " can't execute "
				<< f.getName() << "." << std::endl;
	}
}

std::string	const	&Bureaucrat::getName(void) const { return (_name);}
int					Bureaucrat::getGrade(void) const { return (_grade);}

void				Bureaucrat::signForm(bool sign, Form const &f) const {
	if (sign) {
		std::cout << *this << " signed form:\t" << f << std::endl;
	} else {
		std::cout << *this << " cannot sign form:\t" << f << " because ";
		if (f.getIsSigned()) {
			std::cout << "it's already signed !" << std::endl;
		} else {
			std::cout << "grade isn't high enough"  << std::endl;
		}
	}
}


Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}
Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}

char const			*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high");
}


char const			*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low");
}

std::ostream&	operator<<(std::ostream& stream, Bureaucrat const &s) {
	stream << s.getName() << ", bureaucrat grade " << s.getGrade();
	return (stream);
}
