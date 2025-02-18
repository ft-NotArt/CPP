/* Includes */

#include "ShrubberyCreationForm.hpp"


/* Constructor & Destructor */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("home") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()), target(copy.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


/* Method */

void ShrubberyCreationForm::doFormality() const {
	std::ofstream file((this->target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::app) ;
	if (file.is_open()) {
		file	<< "        &&& &&  & &&     " << std::endl
				<< "    && &\\/&\\|& ()|/ &&   " << std::endl
				<< "    &\\/(/&/&||/& /_/)_&  " << std::endl
				<< "   &() &\\/&|()|/&\\/  &   " << std::endl
				<< " && /\\&/&||/& /&/&\\_&/&& " << std::endl
				<< "   &&&\\|&\\|&&|/&// &&&   " << std::endl
				<< "         &&   |||        " << std::endl
				<< "              |||        " << std::endl
				<< "              |||        " << std::endl ;
	} else
		std::cerr << "Error trying to open " << this->target + "_shruberry" << std::endl ;
}
