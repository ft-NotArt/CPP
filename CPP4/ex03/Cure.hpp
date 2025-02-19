#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <string>
#include <iostream>

class ICharacter ;

class Cure : public AMateria
{
public:
	Cure() ;
	Cure(const Cure &copy) ;
	~Cure() ;
	Cure &operator=(const Cure &copy) ;
	AMateria* clone() const ;
	void use(ICharacter& target) ;
};
