#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	Form("Shrubbery Creation", 145, 137),
	_target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
	Form("Shrubbery Creation", 145, 137) {
	if (this != &src)
		*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

std::string const		&ShrubberyCreationForm::getTarget(void) const {
	return (_target);
}

void					ShrubberyCreationForm::action(void) const
{
	std::ofstream		ofs;

	ofs.open((_target + "_shrubbery").c_str(), std::ios_base::app);
	ofs << std::endl
		<< "         .8.                          .8." << std::endl
		<< "         888                          888" << std::endl
		<< "         888l                         888l" << std::endl
		<< "        j8888.                       j`488." << std::endl
		<< "       .888888.                     .  d888." << std::endl
		<< "      .88888888.                   .88888888." << std::endl
		<< "    .d8888888888b.               .d88888P'`48b." << std::endl
		<< "  .d88888888888888b.           .d8P""488b  d888b." << std::endl
		<< " .888888888888888888b.        .888    88888888888b." << std::endl
		<< ".888888888888888888888       .8888b..d88888888' `88" << std::endl
		<< "8888888888888888888888       88888888888888888. ,88" << std::endl
		<< "888P''''''''''''''4888       888P''''''''''''''4888" << std::endl
		<< "`P'     .    .     `q'       `P'     .    .     `q'" << std::endl
		<< " `-..____:  :____..-'         `-..____:  :____..-'" << std::endl
		<< "         :  :                         :  :" << std::endl
		<< "         :  :                         :  :" << std::endl
		<< "         :  :                         :  :" << std::endl
		<< "         :  :                         :  :" << std::endl
		<< "         :  :                         :  :" << std::endl
		<< "       \\(/\\\\)\\/                     \\(/\\\\)\\/" << std::endl;
}

ShrubberyCreationForm		&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}
