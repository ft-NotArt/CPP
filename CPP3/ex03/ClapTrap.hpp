#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
protected:
	std::string name ;
	int hitPoints ;
	int energyPoints ;
	int attackDamage ;
public:
	ClapTrap() ;
	ClapTrap(std::string name) ;
	ClapTrap(const ClapTrap &cp) ;
	~ClapTrap() ;
	ClapTrap &operator=(const ClapTrap &cp) ;
	const std::string &getName() const ;
	int getHitPoints() const ;
	int getEnergyPoints() const ;
	int getAttackDamage() const ;
	void lackEnergyPoint() const ;
	void lackHitPoint() const ;
	void attack(const std::string& target) ;
	void takeDamage(unsigned int amount) ;
	void beRepaired(unsigned int amount) ;
};

std::ostream &operator<<(std::ostream &out, const ClapTrap &cp) ;
