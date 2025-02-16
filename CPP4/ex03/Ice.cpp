/* Includes */

#include "Ice.hpp"


/* Constructor & Destructor */

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &copy) : AMateria("ice") { (void) copy ; }

Ice::~Ice() {}


/* Operator overload */

Ice &Ice::operator=(const Ice &copy) {
	if (this != &copy) {
		AMateria::operator=(copy);
	}
	return *this;
}


/* Method */

AMateria *Ice::clone() const {
	return ( new Ice(*this) ) ;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl ;
}
