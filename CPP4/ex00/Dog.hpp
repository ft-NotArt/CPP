#pragma once

#include "Animal.hpp"

#include <string>
#include <iostream>

class Dog : public Animal
{
public:
	Dog() ;
	Dog(const Dog &dog) ;
	~Dog() ;
	Dog &operator=(const Dog &dog) ;
	void makeSound() const ;
};
