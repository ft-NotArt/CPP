/* Includes */

#include "FragTrap.hpp"


/* Constructors & Destructor */

FragTrap::FragTrap() : ClapTrap("classic", 100, 100, 30) {
	std::cout << "FragTrap " << this->name << " had just been created (via Default)" << std::endl ;
}

FragTrap::FragTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage) : ClapTrap(name, hitPoints, energyPoints, attackDamage) {
	std::cout << "FragTrap " << this->name << " had just been created (via Args)" << std::endl ;
}

FragTrap::FragTrap(const FragTrap &cp) : ClapTrap(cp) {
	std::cout << "FragTrap " << this->name << " had just been created (via Copy)" << std::endl ;
}


FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " burst in a huge explosion" << std::endl ;
}


/* Operator overload */

FragTrap &FragTrap::operator=(const FragTrap &cp) {
	this->ClapTrap::operator=(cp) ;
	return *this ;
}


/* Methods */

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->name << " wants a HighFive !!!" << std::endl ;
}
