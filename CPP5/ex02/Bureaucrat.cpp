/* Include */

#include "Bureaucrat.hpp"


/* Constructor & Destructor */

Bureaucrat::Bureaucrat() : name("Sylvie"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException() ;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException() ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : name(cpy.name), grade(cpy.grade) {}

Bureaucrat::~Bureaucrat() {}


/* Operator overload */

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy) {
	this->grade = cpy.grade ;
	return *this ;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." ;
	return out ;
}


/* Get */

std::string Bureaucrat::getName() const { return this->name ; }
int Bureaucrat::getGrade() const { return this->grade ; }


/* Methods */

void Bureaucrat::promote() {
	if (this->grade <= 1)
		throw Bureaucrat::GradeTooHighException() ;

	grade-- ;
}

void Bureaucrat::demote() {
	if (this->grade >= 150)
		throw Bureaucrat::GradeTooLowException() ;

	grade++ ;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this) ;
		std::cout << this->name << " signed " << form.getName() << std::endl ;
	} catch(const std::exception& e) {
		std::cerr << this->name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl ;
	}
}

void Bureaucrat::executeForm(const AForm &form) {
	try {
		form.execute(*this) ;
		std::cout << this->name << " executed " << form.getName() << std::endl ;
	} catch(const std::exception& e) {
		std::cerr << this->name << " couldn't execute " << form.getName() << " because " << e.what() << "." << std::endl ;
	}
}


/* Exceptions */

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Bureaucrat::GradeTooHighException (Maximum grade is 1)" ; }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Bureaucrat::GradeLowHighException (Minimum grade is 150)" ; }
