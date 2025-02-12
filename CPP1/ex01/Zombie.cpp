#include "Zombie.hpp"

Zombie::Zombie() {
	this->name = "" ;
}

Zombie::Zombie(std::string name) {
	this->name = name ;
}

Zombie::~Zombie() {
	std::cout << this->name << " walks away..." << std::endl ;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl ;
}

void Zombie::setName(std::string name) { this->name = name ; }
std::string Zombie::getName() { return this->name ; }