#pragma once

#include "Brain.hpp"

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type ;
public:
	Animal() ;
	Animal(const Animal &cpy) ;
	virtual ~Animal() ;
	Animal &operator=(const Animal &animal) ;
	std::string getType() const ;
	virtual void makeSound() const ;
	virtual Brain &getBrain() const = 0 ;
};

