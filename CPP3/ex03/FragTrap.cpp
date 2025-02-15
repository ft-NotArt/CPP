/* Includes */

#include "FragTrap.hpp"


/* Constructors & Destructor */

FragTrap::FragTrap() : ClapTrap("classic") {
	this->hitPoints = 100 ;
	this->energyPoints = 100 ;
	this->attackDamage = 30 ;
	std::cout << "FragTrap " << this->name << " had just been created (via Default)" << std::endl ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100 ;
	this->energyPoints = 100 ;
	this->attackDamage = 30 ;
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
