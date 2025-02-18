#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try { // Trying throw exception TOO HIGH w/ catch ANY EXCEPTION
		Bureaucrat god("god", 0);
	} catch(const std::exception &e) {
		std::cerr << "catching std::exception \n  " << e.what() << std::endl ;
	}
	std::cout << std::endl ;

	try { // Trying throw exception TOO HIGH w/ catch TOO HIGH EXCEPTION
		Bureaucrat god("god", 0);
	} catch(const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "catching Bureaucrat::GradeTooHighException \n  " << e.what() << std::endl ;
	}
	std::cout << std::endl ;

	try { // Trying throw exception TOO HIGH w/ catch TOO LOW EXCEPTION
		Bureaucrat gogole("gogole", 1000000);
	} catch(const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "catching Bureaucrat::GradeTooLowException \n  " << e.what() << std::endl ;
	}
	std::cout << std::endl ;

	try { // Trying throw exception TOO HIGH w/ catch TOO LOW EXCEPTION or ANY EXCEPTION
		Bureaucrat god("god", 0);
	} catch(const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "catching Bureaucrat::GradeTooLowException \n  " << e.what() << std::endl ;
	} catch(const std::exception &e) {
		std::cerr << "catching std::exception \n  " << e.what() << std::endl ;
	}
	std::cout << std::endl ;
	std::cout << std::endl ;

	Bureaucrat boss("Richard", 1) ;
	Bureaucrat bruno("Bruno", 145) ;

	std::cout << boss << std::endl ;
	std::cout << bruno << std::endl ;

	try {
		bruno.promote() ;
	} catch(const std::exception &e) {
		std::cerr << "catching std::exception \n  " << e.what() << std::endl ;
	}
	std::cout << std::endl ;

	std::cout << bruno << std::endl ;
	std::cout << std::endl ;

	try {
		bruno.demote() ;
	} catch(const std::exception &e) {
		std::cerr << "catching std::exception \n  " << e.what() << std::endl ;
	}
	std::cout << std::endl ;

	std::cout << bruno << std::endl ;
	std::cout << std::endl ;

	try {
		bruno.demote() ;
		bruno.demote() ;
		bruno.demote() ;
		bruno.demote() ;
		bruno.demote() ;
		bruno.demote() ;
		bruno.demote() ;
		bruno.demote() ;
		bruno.demote() ;
	} catch(const std::exception &e) {
		std::cerr << "catching std::exception \n  " << e.what() << std::endl ;
	}
	std::cout << std::endl ;

	std::cout << bruno << std::endl ;
	std::cout << std::endl ;

	try {
		boss.promote() ;
	} catch(const std::exception &e) {
		std::cerr << "catching std::exception \n  " << e.what() << std::endl ;
	}
	std::cout << std::endl ;

	std::cout << boss << std::endl ;
}