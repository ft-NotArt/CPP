/* Includes */

#include "Dog.hpp"


/* Constructors & Destructor */

Dog::Dog() {
	this->type = "Dog" ;
	this->brain = new Brain() ;
	std::cout << "A Dog was born (default)" << std::endl ;
}


Dog::Dog(const Dog &dog) /* : Animal(cat) */ { // Since I have to display a specific message for each class, I can't use Animal copy constructor anymore
	this->type = dog.type ;
	this->brain = new Brain(*dog.brain) ;
	std::cout << "A Dog was born (copy)" << std::endl ;
}

Dog::~Dog() {
	delete brain ;
	std::cout << "A Dog was killed" << std::endl ;
}


/* Operator overloads */

Dog &Dog::operator=(const Dog &dog) {
	this->type = dog.type ;
	for (size_t i = 0; i < BRAIN_CAPACITY; i++)
		this->brain->setIdea(dog.brain->getIdea(i), i) ;
	return *this ;
}


/* Get */

Brain &Dog::getBrain() const { return *this->brain ; }


/* Method */

void Dog::makeSound() const {
	std::cout << "Wouf !" << std::endl ;
}
