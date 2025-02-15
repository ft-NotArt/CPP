#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name ;
public:
	DiamondTrap() ;
	DiamondTrap(std::string name) ;
	DiamondTrap(const DiamondTrap &cp) ;
	~DiamondTrap() ;
	DiamondTrap &operator=(const DiamondTrap &cp) ;
	using ScavTrap::attack ;
	void WhoAmI() ;
};
