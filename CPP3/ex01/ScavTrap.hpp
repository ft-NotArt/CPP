#pragma once

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap() ;
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &cp) ;
	~ScavTrap() ;
	ScavTrap &operator=(const ScavTrap &cp) ;
	void attack(const std::string& target) ;
	void guardGate() ;
};
