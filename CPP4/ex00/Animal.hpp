#pragma once

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type ;
public:
	Animal() ;
	Animal(const Animal &cpy) ;
	~Animal() ;
	Animal &operator=(const Animal &animal) ;
	std::string getType() const ;
	virtual void makeSound() const ;
};

