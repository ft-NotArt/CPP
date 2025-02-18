/* Includes */

#include "PresidentialPardonForm.hpp"


/* Constructor & Destructor */

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("home") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()), target(copy.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}


/* Method */

void PresidentialPardonForm::doFormality() const {
	std::cout << this->target << " has formaly been pardoned by Zaphod Beeblebrox" << std::endl ;
}
