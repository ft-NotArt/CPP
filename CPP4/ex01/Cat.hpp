#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>
#include <iostream>

class Cat : public Animal
{
private:
	Brain *brain ;
public:
	Cat() ;
	Cat(const Cat &cat) ;
	~Cat() ;
	Cat &operator=(const Cat &cat) ;
	void makeSound() const ;
	Brain &getBrain() const ;
};
