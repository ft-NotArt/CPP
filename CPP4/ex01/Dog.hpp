#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>
#include <iostream>

class Dog : public Animal
{
private:
	Brain *brain ;
public:
	Dog() ;
	Dog(const Dog &dog) ;
	~Dog() ;
	Dog &operator=(const Dog &dog) ;
	void makeSound() const ;
	Brain &getBrain() const ;
};
