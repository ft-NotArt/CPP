#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"


int main()
{
	IMateriaSource* src = new MateriaSource();
	/* Modified this part of the main as it was irrelevant/absurd for learnMateria to have to delete AMateria instance passed as parameter */
	AMateria *ice = new Ice() ;
	AMateria *cure = new Cure() ;
	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice ;
	delete cure ;

	ICharacter* me = new Character("me");

	/* Same goes here, modified this part of the main as it was irrelevant/absurd for equip to have to delete AMateria instance passed as parameter */
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp ;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp ;

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	return 0;
}