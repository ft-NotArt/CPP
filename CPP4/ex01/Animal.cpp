/* Includes */

#include "Animal.hpp"


/* Constructors & Destructor */

Animal::Animal() : type("Animal") {
	std::cout << "An Animal was born (default)" << std::endl ;
}

Animal::Animal(const Animal &cpy) : type(cpy.type) {
	std::cout << "An Animal was born (copy)" << std::endl ;
}

Animal::~Animal() {
	std::cout << "An Animal was killed" << std::endl ;
}


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
