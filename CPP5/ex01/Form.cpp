/* Includes */

#include "Form.hpp"


/* Constructor & Destructor */

Form::Form() : name("Form"), isSigned(false), gradeToSign(150), gradeToExec(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException() ;
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException() ;
}

Form::Form(const Form &copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExec(copy.gradeToExec) {}

Form::~Form() {}


/* Operator overload */

Form &Form::operator=(const Form &copy) { // Only copying what I can since name and grades are const
	this->isSigned = copy.isSigned ;
	return *this ;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out	<< form.getName()
		<< ", form that " << (form.getIsSigned() ? "is" : "isn't") << " signed, "
		<< (form.getIsSigned() ? "has been" : "must be") << " signed by grades " << form.getGradeToSign() << " or higher "
		<< "and can be executed by grades " << form.getGradeToExec() << " or higher" ;
	return out ;
}


/* Get */

std::string Form::getName() const { return this->name ; }
bool Form::getIsSigned() const { return this->isSigned ; }
int Form::getGradeToSign() const { return this->gradeToSign ; }
int Form::getGradeToExec() const { return this->gradeToExec ; }


/* Method */

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Bureaucrat::GradeTooLowException() ;
	
	this->isSigned = true ;
}


/* Exceptions */

const char *Form::GradeTooHighException::what() const throw() { return "Form::GradeTooHighException" ; }

const char *Form::GradeTooLowException::what() const throw() { return "Form::GradeLowHighException" ; }
