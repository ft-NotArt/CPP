#pragma once

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap : virtual public ClapTrap
{
private:
public:
	FragTrap() ;
	FragTrap(std::string name);
	FragTrap(const FragTrap &cp) ;
	~FragTrap() ;
	FragTrap &operator=(const FragTrap &cp) ;
	void highFivesGuys(void);
};
