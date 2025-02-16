/* Includes */

#include "Cure.hpp"


/* Constructor & Destructor */

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &copy) : AMateria("cure") { (void) copy ; }

Cure::~Cure() {}


/* Operator overload */

Cure &Cure::operator=(const Cure &copy) {
	if (this != &copy) {
		AMateria::operator=(copy);
	}
	return *this;
}


/* Method */

AMateria *Cure::clone() const {
	return ( new Cure(*this) ) ;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl ;
}
