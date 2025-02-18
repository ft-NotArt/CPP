#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>
#include <iostream>

#define NB_FORM_NAMES 3

class Intern
{
public:
	Intern() ;
	Intern(const Intern &copy) ;
	~Intern() ;
	Intern &operator=(const Intern &copy) ;
	AForm *makeForm(std::string formName, std::string formTarget) ;
};
