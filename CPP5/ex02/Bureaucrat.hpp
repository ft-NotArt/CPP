#pragma once

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <exception>

class AForm ;

class Bureaucrat {
private:
	const std::string name ;
	int grade ;
public:
	Bureaucrat() ;
	Bureaucrat(std::string name, int grade) ;
	Bureaucrat(const Bureaucrat &cpy) ;
	~Bureaucrat() ;
	Bureaucrat &operator=(const Bureaucrat &cpy) ;
	std::string getName() const ;
	int getGrade() const ;
	void promote() ;
	void demote() ;
	void signForm(AForm &form) ;
	void executeForm(AForm const &form) ;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;

	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) ;