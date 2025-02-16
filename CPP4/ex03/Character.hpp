#pragma once

#include "ICharacter.hpp"

#include <string>
#include <iostream>

#define NB_ITEM_MAX 4

class Character : public ICharacter
{
private:
	AMateria *stuff[NB_ITEM_MAX] ;
public:
	Character() ;
	Character(std::string name) ;
	Character(const Character &copy) ;
	~Character() ;
	Character &operator=(const Character &copy) ;
	std::string const & getName() const ;
	void equip(AMateria* m) ;
	void unequip(int idx) ;
	void use(int idx, ICharacter& target) ;
};
