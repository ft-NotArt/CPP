/* Includes */

#include "WrongAnimal.hpp"


/* Constructors & Destructor */

WrongAnimal::WrongAnimal() : type("WrongAnimal") {}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy) : type(cpy.type) {}

WrongAnimal::~WrongAnimal() {}


/* Operator overloads */

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
	this->type = wrongAnimal.type ;
	return *this ;
}


/* Get */

std::string WrongAnimal::getType() const { return this->type ; }


/* Method */

void WrongAnimal::makeSound() const {
	std::cout << "No WrongAnimal, makes no sound..." << std::endl ;
}
