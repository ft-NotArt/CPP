#pragma once

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap() ;
	ScavTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
	ScavTrap(const ScavTrap &cp) ;
	~ScavTrap() ;
	ScavTrap &operator=(const ScavTrap &cp) ;
	void attack(const std::string& target) ;
	void guardGate() ;
};
