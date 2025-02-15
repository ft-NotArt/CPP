/* Includes */

#include "Cat.hpp"


/* Constructors & Destructor */

Cat::Cat() {
	this->type = "Cat" ;
}

Cat::Cat(const Cat &cat) : Animal(cat) {}

Cat::~Cat() {}


/* Operator overloads */

Cat &Cat::operator=(const Cat &cat) {
	this->type = cat.type ;
	return *this ;
}


/* Method */

void Cat::makeSound() const {
	std::cout << "Meow..." << std::endl ;
}
