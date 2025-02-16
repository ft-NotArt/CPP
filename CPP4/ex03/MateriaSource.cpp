/* Include */

#include "MateriaSource.hpp"


/* Constructors & Destructor */

MateriaSource::MateriaSource() {
	for (size_t i = 0; i < NB_RECIPES_MAX; i++) {
		this->recipes[i] = NULL ;
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	for (size_t i = 0; i < NB_RECIPES_MAX; i++) {
		this->recipes[i] = (copy.recipes[i] != NULL) ? copy.recipes[i]->clone() : NULL ;
	}
}

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < NB_RECIPES_MAX; i++) {
		if (this->recipes[i]) // Checking for NULL for logical purpose, but wouldn't do anything to call delete on NULL
			delete recipes[i] ;
	}
}


/* Operator overload */

MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
	for (size_t i = 0; i < NB_RECIPES_MAX; i++) {
		if (this->recipes[i]) // Checking for NULL for logical purpose, but wouldn't do anything to call delete on NULL
			delete recipes[i] ;
		this->recipes[i] = (copy.recipes[i] != NULL) ? copy.recipes[i]->clone() : NULL ;
	}
	return *this ;
}


/* Methods */

/***
 * @param m should be the adress of STACK allocated AMateria, not a pointer to an AMateria, as it wouldn't be deleted in any case (or delete it yourself in main)
 */
void MateriaSource::learnMateria(AMateria *m) {
	for (size_t i = 0; i < NB_RECIPES_MAX; i++) {
		if (!this->recipes[i]) {
			this->recipes[i] = m->clone() ;
			return ;
		}
	}
	std::cout << "This MateriaSource has already learnt its maximum recipes !" << std::endl ;
}

AMateria *MateriaSource::createMateria(std::string const & type) {
	for (int i = NB_RECIPES_MAX - 1 ; i >= 0; i--) {
		if (this->recipes[i] != NULL && this->recipes[i]->getType() == type)
			return ( this->recipes[i]->clone() ) ;
	}
	std::cout << "This MateriaSource doesn't know any recipe for type : " << type << std::endl ;
	return NULL ;
}