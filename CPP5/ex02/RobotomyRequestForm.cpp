/* Includes */

#include "RobotomyRequestForm.hpp"


/* Constructor & Destructor */

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("home") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()), target(copy.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}


/* Method */

void RobotomyRequestForm::doFormality() const {
	std::cout << "BZZZZZZZ!RRRRRRRR!Drrrrrrr!" << std::endl ;
	srand(time(NULL)) ;
	if ((rand() % 2) == 0)
		std::cout << this->target << " has been robotomized !" << std::endl ;
	else
		std::cout << "Robotomy for " << this->target << " failed..." << std::endl ;
}
