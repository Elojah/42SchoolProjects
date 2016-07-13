#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(std::string const &name, int const gradeRequiredSign, int const gradeRequiredExe):
	_name(name),
	_isSigned(false),
	_gradeRequiredSign(gradeRequiredSign),
	_gradeRequiredExe(gradeRequiredExe) {
	if (_gradeRequiredSign < 1 || _gradeRequiredExe < 1)
		throw GradeTooHighException();
	else if (_gradeRequiredSign > 150 || _gradeRequiredExe > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &src) :
	_name(""),
	_gradeRequiredSign(0),
	_gradeRequiredExe(0) {
	if (this != &src)
		*this = src;
}

Form::~Form(void) {
}

std::string		Form::getName(void) const {
	return (_name);
}

bool			Form::getIsSigned(void) const {
	return (_isSigned);
}

int				Form::getGradeRequiredSign(void) const {
	return (_gradeRequiredSign);
}

int				Form::getGradeRequiredExe(void) const {
	return (_gradeRequiredExe);
}

void			Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > _gradeRequiredSign) {
		throw GradeTooLowException();
	} else if (!_isSigned) {
		_isSigned = true;
		b.signForm(true, *this);
		return ;
	}
	b.signForm(false, *this);
}

Form		&Form::operator=(Form const &rhs) {
	if (this != &rhs) {
		_isSigned = rhs._isSigned;
	}
	return (*this);
}

Form::GradeTooHighException::GradeTooHighException(void) {}
Form::GradeTooHighException::~GradeTooHighException(void) throw() {}
Form::GradeTooLowException::GradeTooLowException(void) {}
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}
char const				*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}
char const				*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

std::ostream&	operator<<(std::ostream& stream, Form const &s) {
	stream << "Form " << s.getName() << ": require sign by " << s.getGradeRequiredSign() << " and exec by " << s.getGradeRequiredExe();
	if (s.getIsSigned()) {
		stream << " is signed !";
	} else {
		stream << " is not signed yet";
	}
	return (stream);
}
