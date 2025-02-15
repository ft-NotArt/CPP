#pragma once

#include "WrongAnimal.hpp"

#include <string>
#include <iostream>

class WrongCat : public WrongAnimal
{
public:
	WrongCat() ;
	WrongCat(const WrongCat &wrongCat) ;
	~WrongCat() ;
	WrongCat &operator=(const WrongCat &wrongCat) ;
	void makeSound() const ;
};
