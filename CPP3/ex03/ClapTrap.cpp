/* Includes */

#include "ClapTrap.hpp"


/* Constructors & Destructor */

ClapTrap::ClapTrap() : name("basic"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " had just been created (via Default)" << std::endl ;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " had just been created (via Args)" << std::endl ;
}

ClapTrap::ClapTrap(const ClapTrap &cp) : name(cp.name), hitPoints(cp.hitPoints), energyPoints(cp.energyPoints), attackDamage(cp.attackDamage) {
	std::cout << "ClapTrap " << this->name << " had just been created (via Copy)" << std::endl ;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " burst in a tumultuous explosion" << std::endl ;
}


/* Operator overload */

ClapTrap &ClapTrap::operator=(const ClapTrap &cp) {
	this->name = cp.name ;
	this->hitPoints = cp.hitPoints ;
	this->energyPoints = cp.energyPoints ;
	this->attackDamage = cp.attackDamage ;

	return *this ;
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &cp) {
	out << "ClapTrap " << cp.getName() << " has " << cp.getHitPoints() << " Hit Points, " << cp.getEnergyPoints() << " Energy Points, and deals " << cp.getAttackDamage() << " damages when attacking" ;
	return out ;
}


/* Get and Set */

const std::string &ClapTrap::getName() const { return this->name ; }
int ClapTrap::getHitPoints() const { return this->hitPoints ; }
int ClapTrap::getEnergyPoints() const { return this->energyPoints ; }
int ClapTrap::getAttackDamage() const { return this->attackDamage ; }


/* Methods */

void ClapTrap::lackEnergyPoint() const {
	std::cout << "ClapTrap " << this->name << "doesn't have enough energy points !" << std::endl ;
}

void ClapTrap::lackHitPoint() const {
	std::cout << "ClapTrap " << this->name << "doesn't have enough hit points !" << std::endl ;
}

void ClapTrap::attack(const std::string& target) {
	if (this->hitPoints <= 0) {
		this->lackHitPoint() ;
		return ;
	}
	if (this->energyPoints <= 0) {
		this->lackEnergyPoint() ;
		return ;
	}
	this->energyPoints -= 1 ;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage" << std::endl ;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage" << std::endl ;
	this->hitPoints -= amount ;
	if (this->hitPoints < 0)
		this->hitPoints = 0 ;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints <= 0) {
		this->lackHitPoint() ;
		return ;
	}
	if (this->energyPoints <= 0) {
		this->lackEnergyPoint() ;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " is being repared, healing " << amount << " hit points" << std::endl ;
	this->hitPoints += amount ;
}