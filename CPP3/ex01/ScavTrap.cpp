/* Includes */

#include "ScavTrap.hpp"


/* Constructors & Destructor */

ScavTrap::ScavTrap() : ClapTrap("normal", 100, 50, 20) {
	std::cout << "ScavTrap " << this->name << " had just been created (via Default)" << std::endl ;
}

ScavTrap::ScavTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage) : ClapTrap(name, hitPoints, energyPoints, attackDamage) {
	std::cout << "ScavTrap " << this->name << " had just been created (via Args)" << std::endl ;
}

ScavTrap::ScavTrap(const ScavTrap &cp) : ClapTrap(cp) {
	std::cout << "ScavTrap " << this->name << " had just been created (via Copy)" << std::endl ;
}


ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " burst in a clinky explosion" << std::endl ;
}


/* Operator overload */

ScavTrap &ScavTrap::operator=(const ScavTrap &cp) {
	this->ClapTrap::operator=(cp) ;
	return *this ;
}


/* Methods */

void ScavTrap::attack(const std::string& target) {
	if (this->hitPoints <= 0) {
		this->lackHitPoint() ;
		return ;
	}
	if (this->energyPoints <= 0) {
		this->lackEnergyPoint() ;
		return ;
	}
	this->energyPoints -= 1 ;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", inflicting " << this->attackDamage << " points of damage" << std::endl ;
}


void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is name in guard mode" << std::endl ;
}
