/* Includes */

#include "Cat.hpp"


/* Constructors & Destructor */

Cat::Cat() {
	this->type = "Cat" ;
	this->brain = new Brain() ;
	std::cout << "A Cat was born (default)" << std::endl ;
}

Cat::Cat(const Cat &cat) /* : Animal(cat) */ { // Since I have to display a specific message for each class, I can't use Animal copy constructor anymore
	this->type = cat.type ;
	this->brain = new Brain(*cat.brain) ;
	std::cout << "A Cat was born (copy)" << std::endl ;
}

Cat::~Cat() {
	delete brain ;
	std::cout << "A Cat was killed" << std::endl ;
}


/* Operator overloads */

Cat &Cat::operator=(const Cat &cat) {
	this->type = cat.type ;
	for (size_t i = 0; i < BRAIN_CAPACITY; i++)
		this->brain->setIdea(cat.brain->getIdea(i), i) ;
	return *this ;
}


/* Get */

Brain &Cat::getBrain() const { return *this->brain ; }


/* Method */

void Cat::makeSound() const {
	std::cout << "Meow..." << std::endl ;
}
