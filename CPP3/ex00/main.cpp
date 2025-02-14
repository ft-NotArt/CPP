#include "ClapTrap.hpp"
#include <iostream>

int main() {
	ClapTrap cp1 ;
	ClapTrap cp2("bili", 5, 15, 2) ;
	ClapTrap cp3(cp2) ;
	ClapTrap cp4 = cp2 ;

	cp1.attack("gribouille") ;
	cp1.takeDamage(8) ;
	cp1.beRepaired(5) ;


	std::cout << cp4 << std::endl ;

	std::cout << cp1 << std::endl ;
	cp1 = cp4 ;
	std::cout << cp1 << std::endl ;

	return 0 ;
}