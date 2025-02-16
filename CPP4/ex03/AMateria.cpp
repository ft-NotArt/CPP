/* Includes */

#include "AMateria.hpp"


/* Constructor & Destructor */

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::~AMateria() {}


/* Get */

const std::string &AMateria::getType() const { return this->type ; }


/* Method */

void AMateria::use(ICharacter &target) { (void) target ; } // Shouldn't get to this point of the code anyway, as use has to be redefined in each concrete class that'll use it
