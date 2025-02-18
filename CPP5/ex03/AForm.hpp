#pragma once

#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

class Bureaucrat ;

class AForm
{
private:
	const std::string name ;
	bool isSigned ;
	const int gradeToSign ;
	const int gradeToExec ;
public:
	AForm() ;
	AForm(const AForm &copy) ;
	AForm(std::string name, int gradeToSign, int gradeToExec) ;
	virtual ~AForm() ;
	AForm &operator=(const AForm &copy) ;
	std::string getName() const ;
	bool getIsSigned() const ;
	int getGradeToSign() const ;
	int getGradeToExec() const ;
	void beSigned(const Bureaucrat &bureaucrat) ;
	void execute(Bureaucrat const &executor) const ;
	virtual void doFormality() const = 0 ;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;

	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;

	class FormNotSignedException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;
};

std::ostream &operator<<(std::ostream &out, const AForm &form) ;
