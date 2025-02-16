/* Includes */

#include "Brain.hpp"


/* Constructors & destructor */

Brain::Brain() {
	std::cout << "A Brain was made (default)" << std::endl ;
}

Brain::Brain(const Brain &brain) {
	for (size_t i = 0; i < BRAIN_CAPACITY; i++)
		this->ideas[i] = brain.ideas[i] ;
	std::cout << "A Brain was made (copy)" << std::endl ;
}

Brain::~Brain() {
	std::cout << "A Brain was destroyed" << std::endl ;
}


/* Operator overloads */

Brain &Brain::operator=(const Brain &brain) {
	for (size_t i = 0; i < BRAIN_CAPACITY; i++)
		this->ideas[i] = brain.ideas[i] ;
	return *this ;
}


/* Get & Set */

std::string Brain::getIdea(int index) const { return this->ideas[index] ; }

void Brain::setIdea(std::string idea, int index) { this->ideas[index] = idea ; }
