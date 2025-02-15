/* Includes */

#include "Animal.hpp"


/* Constructors & Destructor */

Animal::Animal() : type("Animal") {}

Animal::Animal(const Animal &cpy) : type(cpy.type) {}

Animal::~Animal() {}


/* Operator overloads */

Animal &Animal::operator=(const Animal &animal) {
	this->type = animal.type ;
	return *this ;
}


/* Get */

std::string Animal::getType() const { return this->type ; }


/* Method */

void Animal::makeSound() const {
	std::cout << "No Animal, makes no sound..." << std::endl ;
}
