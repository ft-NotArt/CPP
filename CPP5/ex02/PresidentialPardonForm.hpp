#pragma once

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

class PresidentialPardonForm : public AForm
{
private:
	std::string target ;
public:
	PresidentialPardonForm() ;
	PresidentialPardonForm(std::string target) ;
	PresidentialPardonForm(const PresidentialPardonForm &copy) ;
	~PresidentialPardonForm() ;
	virtual void doFormality() const ;
};
