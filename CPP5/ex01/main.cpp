#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	Bureaucrat boss("Richard", 1) ;
	Bureaucrat bruno("Bruno", 145) ;
	Form brunoResignation("ResignationLetter", 50, 50) ;

	std::cout << boss << std::endl ;
	std::cout << bruno << std::endl ;
	std::cout << brunoResignation << std::endl ;

	bruno.signForm(brunoResignation) ;

	std::cout << std::endl ;
	std::cout << boss << std::endl ;
	std::cout << bruno << std::endl ;
	std::cout << brunoResignation << std::endl ;

	boss.signForm(brunoResignation) ;

	std::cout << std::endl ;
	std::cout << boss << std::endl ;
	std::cout << bruno << std::endl ;
	std::cout << brunoResignation << std::endl ;


}