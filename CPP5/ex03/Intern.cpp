/* Includes */

#include "Intern.hpp"


/* Constructor & Destructor */

Intern::Intern() {}

Intern::Intern(const Intern &copy) { (void) copy ; }

Intern::~Intern() {}


/* Operator overload */

Intern &Intern::operator=(const Intern &copy) {
	(void) copy ;
	return *this ;
}


/* Method */

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
	static const std::string formNames[NB_FORM_NAMES] = {"shrubbery creation", "robotomy request", "presidential pardon"} ;
	
	int i ;
	for (i = 0; i < NB_FORM_NAMES && formNames[i] != formName; i++) ;
	
	if (i == NB_FORM_NAMES) {
		std::cout << "Intern couldn't create " << formName << std::endl ;
		return NULL ;
	}

	std::cout << "Intern creates " ;
	switch (i) {
	case 0 :
		std::cout << "ShrubberyCreationForm" << std::endl ;
		return (new ShrubberyCreationForm(formTarget)) ;
	case 1 :
		std::cout << "RobotomyRequestForm" << std::endl ;
		return (new RobotomyRequestForm(formTarget)) ;
	case 2 :
		std::cout << "PresidentialPardonForm" << std::endl ;
		return (new PresidentialPardonForm(formTarget)) ;
	default:
		return NULL ; // Shouldn't arrive at this point as it was handled previously
	}
}