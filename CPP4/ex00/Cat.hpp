#pragma once

#include "Animal.hpp"

#include <string>
#include <iostream>

class Cat : public Animal
{
public:
	Cat() ;
	Cat(const Cat &cat) ;
	~Cat() ;
	Cat &operator=(const Cat &cat) ;
	void makeSound() const ;
};
