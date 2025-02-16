#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "Brain.hpp"

#include <sstream>

#define ZOO_CAPACITY 10

int main()
{
	Animal *zoo[ZOO_CAPACITY] ;

	for (size_t i = 0; i < ZOO_CAPACITY; i++) {
		if (i % 2)
			zoo[i] = new Dog() ;
		else
			zoo[i] = new Cat() ;

		std::cout << std::endl ;
	}

	std::cout << std::endl ;
	std::cout << std::endl ;
	std::cout << std::endl ;

	for (size_t i = 0; i < ZOO_CAPACITY; i++) {
		zoo[i]->makeSound() ;
	}

	std::cout << std::endl ;
	std::cout << std::endl ;
	std::cout << std::endl ;

	std::stringstream ss ;
	for (int i = 0; i < ZOO_CAPACITY; i++) {
		ss << (i + 1) ;
		zoo[i]->getBrain().setIdea("randomidea" + ss.str(), i) ;
		ss.str("") ;
	}

	std::cout << std::endl ;
	std::cout << std::endl ;
	std::cout << std::endl ;

	for (size_t i = 0; i < ZOO_CAPACITY; i++) {
		for (size_t j = 0; j < BRAIN_CAPACITY; j++) {
			if (zoo[i]->getBrain().getIdea(j) != "") {
				std::cout	<< "Animal of type " << zoo[i]->getType()
							<< " has the idea : " << zoo[i]->getBrain().getIdea(j)
							<< " at index " << j << " into its brain"
				<< std::endl ;
			}
		}
	}

	std::cout << std::endl ;
	std::cout << std::endl ;
	std::cout << std::endl ;

	for (size_t i = 0; i < ZOO_CAPACITY; i++) {
		delete zoo[i] ;

		std::cout << std::endl ;
	}

	return 0;
}