#pragma once

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	std::string target ;
public:
	RobotomyRequestForm() ;
	RobotomyRequestForm(std::string target) ;
	RobotomyRequestForm(const RobotomyRequestForm &copy) ;
	~RobotomyRequestForm() ;
	void doFormality() const ;
};
