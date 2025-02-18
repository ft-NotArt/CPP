#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Bureaucrat boss("Richard", 1) ;
	Intern dude ;
	AForm *form ;

	form = dude.makeForm("tEst", "TeSt") ;
	if (form) {
		boss.signForm(*form) ;
		boss.executeForm(*form) ;
	}
	delete form ;
	std::cout << std::endl ;

	form = dude.makeForm("shrubbery creation", "cool") ;
	if (form) {
		boss.signForm(*form) ;
		boss.executeForm(*form) ;
	}
	delete form ;
	std::cout << std::endl ;

	form = dude.makeForm("robotomy request", "auto") ;
	if (form) {
		boss.signForm(*form) ;
		boss.executeForm(*form) ;
	}
	delete form ;
	std::cout << std::endl ;

	form = dude.makeForm("presidential pardon", "Omar") ;
	if (form) {
		boss.signForm(*form) ;
		boss.executeForm(*form) ;
	}
	delete form ;
	std::cout << std::endl ;
}