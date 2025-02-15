/* Includes */

#include "WrongCat.hpp"


/* Constructors & Destructor */

WrongCat::WrongCat() {
	this->type = "WrongCat" ;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat) {}

WrongCat::~WrongCat() {}


/* Operator overloads */

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
	this->type = wrongCat.type ;
	return *this ;
}


/* Method */

void WrongCat::makeSound() const {
	std::cout << "Meow..." << std::endl ;
}
