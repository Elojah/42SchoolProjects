#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int			main(void)
{
	Bureaucrat				a("Jack", 148);
	Bureaucrat				b("Joe", 5);
	Bureaucrat				c("John", 150);
	ShrubberyCreationForm	sCF("Roomush");
	PresidentialPardonForm	pPF("Stupid");
	RobotomyRequestForm		rRF("Your corrector");

	std::cout << "------------------------" << std::endl;
	std::cout << sCF << std::endl;
	try {sCF.execute(b);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	try {sCF.beSigned(b);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	try {sCF.execute(c);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	try {sCF.execute(b);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	std::cout << "------------------------" << std::endl;
	std::cout << pPF << std::endl;
	try {pPF.execute(b);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	try {pPF.beSigned(b);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	try {pPF.execute(c);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	try {pPF.execute(b);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	std::cout << "------------------------" << std::endl;
	std::cout << rRF << std::endl;
	try {c.executeForm(rRF);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	try {b.executeForm(rRF);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	rRF.beSigned(b);
	try {c.executeForm(rRF);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	try {c.executeForm(rRF);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	try {c.executeForm(rRF);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	try {b.executeForm(rRF);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	return (0);
}
