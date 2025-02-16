#pragma once

#include "IMateriaSource.hpp"

#include <string>
#include <iostream>

#define NB_RECIPES_MAX 4

class MateriaSource : public IMateriaSource
{
private:
	AMateria *recipes[NB_RECIPES_MAX] ;
public:
	MateriaSource() ;
	MateriaSource(const MateriaSource &copy) ;
	~MateriaSource() ;
	MateriaSource &operator=(const MateriaSource &copy) ;
	void learnMateria(AMateria*) ;
	AMateria* createMateria(std::string const & type) ;
};