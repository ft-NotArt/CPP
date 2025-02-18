#pragma once

#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

class Bureaucrat ;

class Form
{
private:
	const std::string name ;
	bool isSigned ;
	const int gradeToSign ;
	const int gradeToExec ;
public:
	Form() ;
	Form(const Form &copy) ;
	Form(std::string name, int gradeToSign, int gradeToExec) ;
	~Form() ;
	Form &operator=(const Form &copy) ;
	std::string getName() const ;
	bool getIsSigned() const ;
	int getGradeToSign() const ;
	int getGradeToExec() const ;
	void beSigned(const Bureaucrat &bureaucrat) ;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;

	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;
};

std::ostream &operator<<(std::ostream &out, const Form &form) ;