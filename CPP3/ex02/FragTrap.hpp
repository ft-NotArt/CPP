#pragma once

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap : public ClapTrap
{
private:
public:
	FragTrap() ;
	FragTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
	FragTrap(const FragTrap &cp) ;
	~FragTrap() ;
	FragTrap &operator=(const FragTrap &cp) ;
	void highFivesGuys(void);
};
