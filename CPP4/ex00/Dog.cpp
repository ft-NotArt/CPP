/* Includes */

#include "Dog.hpp"


/* Constructors & Destructor */

Dog::Dog() {
	this->type = "Dog" ;
}

Dog::Dog(const Dog &dog) : Animal(dog) {}

Dog::~Dog() {}


/* Operator overloads */

Dog &Dog::operator=(const Dog &dog) {
	this->type = dog.type ;
	return *this ;
}


/* Method */

void Dog::makeSound() const {
	std::cout << "Wouf !" << std::endl ;
}
