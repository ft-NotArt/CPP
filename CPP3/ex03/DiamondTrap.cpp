/* Includes */

#include "DiamondTrap.hpp"


/* Constructors & Destructor */

DiamondTrap::DiamondTrap() : ClapTrap("classy_clap_name"), name("classy") {
	this->hitPoints = FragTrap::hitPoints ;
	this->energyPoints = ScavTrap::energyPoints ;
	this->attackDamage = FragTrap::attackDamage ;
	std::cout << "DiamondTrap " << this->name << " had just been created (via Default)" << std::endl ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name) {
	this->hitPoints = FragTrap::hitPoints ;
	this->energyPoints = ScavTrap::energyPoints ;
	this->attackDamage = FragTrap::attackDamage ;
	std::cout << "DiamondTrap " << this->name << " had just been created (via Args)" << std::endl ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cp) : ClapTrap(cp), name(cp.name) {
	std::cout << "DiamondTrap " << this->name << " had just been created (via Copy)" << std::endl ;
}


DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " burst in a shining explosion" << std::endl ;
}


/* Operator overload */

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cp) {
	this->name = cp.name ;
	this->ClapTrap::operator=(cp) ;
	return *this ;
}


/* Methods */

void DiamondTrap::WhoAmI() {
	std::cout << "Who Am I ? My name is " << ClapTrap::name << ", but you can also call me " << this->name << std::endl ;
}
