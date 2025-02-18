#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	Bureaucrat boss("Richard", 1) ;
	Bureaucrat bruno("Bruno", 145) ;
	ShrubberyCreationForm coolTree("cool") ;
	RobotomyRequestForm robot("coffee_making") ;
	PresidentialPardonForm inmate("A cold blood murderer of a family of 7") ;

	std::cout << boss << std::endl ;
	std::cout << bruno << std::endl ;
	std::cout << coolTree << std::endl ;
	std::cout << std::endl ;

	boss.executeForm(coolTree) ;
	bruno.signForm(coolTree) ;
	boss.signForm(coolTree) ;

	std::cout << std::endl ;
	std::cout << boss << std::endl ;
	std::cout << bruno << std::endl ;
	std::cout << coolTree << std::endl ;
	std::cout << std::endl ;

	bruno.executeForm(coolTree) ;
	boss.executeForm(coolTree) ;

	std::cout << std::endl ;
	std::cout << boss << std::endl ;
	std::cout << bruno << std::endl ;
	std::cout << coolTree << std::endl ;
	std::cout << std::endl ;

	std::cout << "==========================" << std::endl ;
	std::cout << std::endl ;

	std::cout << boss << std::endl ;
	std::cout << bruno << std::endl ;
	std::cout << robot << std::endl ;
	std::cout << std::endl ;

	boss.executeForm(robot) ;
	bruno.signForm(robot) ;
	boss.signForm(robot) ;

	std::cout << std::endl ;
	std::cout << boss << std::endl ;
	std::cout << bruno << std::endl ;
	std::cout << robot << std::endl ;
	std::cout << std::endl ;

	bruno.executeForm(robot) ;
	boss.executeForm(robot) ;

	std::cout << std::endl ;
	std::cout << boss << std::endl ;
	std::cout << bruno << std::endl ;
	std::cout << robot << std::endl ;
	std::cout << std::endl ;

	std::cout << "==========================" << std::endl ;
	std::cout << std::endl ;

	std::cout << boss << std::endl ;
	std::cout << bruno << std::endl ;
	std::cout << inmate << std::endl ;
	std::cout << std::endl ;

	boss.executeForm(inmate) ;
	bruno.signForm(inmate) ;
	boss.signForm(inmate) ;

	std::cout << std::endl ;
	std::cout << boss << std::endl ;
	std::cout << bruno << std::endl ;
	std::cout << inmate << std::endl ;
	std::cout << std::endl ;

	bruno.executeForm(inmate) ;
	boss.executeForm(inmate) ;

	std::cout << std::endl ;
	std::cout << boss << std::endl ;
	std::cout << bruno << std::endl ;
	std::cout << inmate << std::endl ;
	std::cout << std::endl ;
}