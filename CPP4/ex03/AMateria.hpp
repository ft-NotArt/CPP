#pragma once

#include "ICharacter.hpp"
class ICharacter ;

#include <string>

class AMateria
{
protected:
	std::string type ;
public:
	AMateria(std::string const & type) ;
	virtual ~AMateria() ;
	std::string const & getType() const ;
	virtual AMateria* clone() const = 0 ;
	virtual void use(ICharacter& target) ; // Why couldn't I just throw a const = 0 here ?
};
