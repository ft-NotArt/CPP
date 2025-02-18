#pragma once

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string target ;
public:
	ShrubberyCreationForm() ;
	ShrubberyCreationForm(std::string target) ;
	ShrubberyCreationForm(const ShrubberyCreationForm &copy) ;
	~ShrubberyCreationForm() ;
	virtual void doFormality() const ;
};
