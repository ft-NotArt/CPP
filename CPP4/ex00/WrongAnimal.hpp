#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string type ;
public:
	WrongAnimal() ;
	WrongAnimal(const WrongAnimal &cpy) ;
	~WrongAnimal() ;
	WrongAnimal &operator=(const WrongAnimal &wrongAnimal) ;
	std::string getType() const ;
	void makeSound() const ; // Only diff from normal Animal is here, missing virtual
};

