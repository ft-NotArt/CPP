/* Include */

#include "Character.hpp"


/* Constructors & Destructor */

Character::Character() {
	this->name = "Random" ;
	for (size_t i = 0; i < NB_ITEM_MAX; i++) {
		this->stuff[i] = NULL ;
	}
}

Character::Character(std::string name) {
	this->name = name ;
	for (size_t i = 0; i < NB_ITEM_MAX; i++) {
		this->stuff[i] = NULL ;
	}
}

Character::Character(const Character &copy) {
	this->name = copy.name ;
	for (size_t i = 0; i < NB_ITEM_MAX; i++) {
		this->stuff[i] = copy.stuff[i]->clone() ;
	}
}

Character::~Character() {
	for (size_t i = 0; i < NB_ITEM_MAX; i++) {
		if (this->stuff[i]) // Checking for NULL for logical purpose, but wouldn't do anything to call delete on NULL
			delete stuff[i] ;
	}
}


/* Operator overload */

Character &Character::operator=(const Character &copy) {
	this->name = copy.name ;
	for (size_t i = 0; i < NB_ITEM_MAX; i++) {
		if (this->stuff[i]) // Checking for NULL for logical purpose, but wouldn't do anything to call delete on NULL
			delete stuff[i] ;
		this->stuff[i] = copy.stuff[i]->clone() ;
	}
	return *this ;
}


/* Get */

const std::string &Character::getName() const { return this->name ; }


/* Method */

/***
 * @param m should be the adress of STACK allocated AMateria, not a pointer to an AMateria, as it wouldn't be deleted in any case (or delete it yourself in main)
 */
void Character::equip(AMateria* m) {
	for (size_t i = 0; i < NB_ITEM_MAX; i++) {
		if (!this->stuff[i]) {
			std::cout << this->getName() << " added " << m->getType() << " in slot " << i << " of its stuff !" << std::endl ;
			this->stuff[i] = m->clone() ;
			return ;
		}
	}
	// Subject states that NOTHING should be done in this case, I decided to add this however in a clarity purpose
	std::cout << this->getName() << "'s stuff is already full !" << std::endl ;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < NB_ITEM_MAX && this->stuff[idx] != NULL) {
		delete this->stuff[idx] ;
		this->stuff[idx] = NULL ;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < NB_ITEM_MAX && this->stuff[idx]) {
		this->stuff[idx]->use(target) ;
	}
}
