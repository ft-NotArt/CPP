/* Includes */

#include "AForm.hpp"


/* Constructor & Destructor */

AForm::AForm() : name("AForm"), isSigned(false), gradeToSign(150), gradeToExec(150) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {}

AForm::AForm(const AForm &copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExec(copy.gradeToExec) {}

AForm::~AForm() {}


/* Operator overload */

AForm &AForm::operator=(const AForm &copy) { // Only copying what I can since name and grades are const
	this->isSigned = copy.isSigned ;
	return *this ;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out	<< form.getName()
		<< ", form that " << (form.getIsSigned() ? "is" : "isn't") << " signed, "
		<< (form.getIsSigned() ? "has been" : "must be") << " signed by grades " << form.getGradeToSign() << " or higher "
		<< "and can be executed by grades " << form.getGradeToExec() << " or higher" ;
	return out ;
}


/* Get */

std::string AForm::getName() const { return this->name ; }
bool AForm::getIsSigned() const { return this->isSigned ; }
int AForm::getGradeToSign() const { return this->gradeToSign ; }
int AForm::getGradeToExec() const { return this->gradeToExec ; }


/* Method */

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException() ;
	
	this->isSigned = true ;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->gradeToExec)
		throw AForm::GradeTooLowException() ;
	if (!this->isSigned)
		throw AForm::FormNotSignedException() ;
	this->doFormality() ;
}

/* Exceptions */

const char *AForm::GradeTooHighException::what() const throw() { return "Form::GradeTooHighException" ; }

const char *AForm::GradeTooLowException::what() const throw() { return "Form::GradeTooLowException" ; }

const char *AForm::FormNotSignedException::what() const throw() { return "Form::FormNotSignedException (Form must be signed before being executed)" ; }
