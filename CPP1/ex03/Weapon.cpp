#include "Weapon.hpp"

#include <iostream>
Weapon::Weapon() {
	this->type = "just arms" ;
}

Weapon::Weapon(std::string type) {
	this->type = type ;
}

Weapon::~Weapon() {}

void Weapon::setType(std::string type) { this->type = type ; }

std::string Weapon::getType() { return this->type ; }
