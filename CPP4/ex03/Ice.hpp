#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <string>
#include <iostream>

class Ice : public AMateria
{
public:
	Ice() ;
	Ice(const Ice &copy) ;
	~Ice() ;
	Ice &operator=(const Ice &copy) ;
	AMateria* clone() const ;
	void use(ICharacter& target) ;
};
