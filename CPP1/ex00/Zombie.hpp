#pragma once

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string name ;
public:
	Zombie(std::string name) ;
	~Zombie() ;
	void announce(void) ;
	std::string getName() ;
};

Zombie *newZombie(std::string name) ;
void randomChump(std::string name) ;
