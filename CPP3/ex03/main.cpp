#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	DiamondTrap dm1 ;

	DiamondTrap dm2("bouli") ;

	DiamondTrap dm3(dm2) ;

	std::cout << std::endl ;

	std::cout << dm1 << std::endl ;
	std::cout << dm2 << std::endl ;
	std::cout << dm3 << std::endl ;

	std::cout << std::endl ;
	dm1.takeDamage(20);
	dm3 = dm1 ;
	std::cout << std::endl ;

	std::cout << dm1 << std::endl ;
	std::cout << dm2 << std::endl ;
	std::cout << dm3 << std::endl ;

	std::cout << std::endl ;

	dm1.attack("anenemythatseemsthreatening") ;
	dm1.takeDamage(5) ;
	dm1.beRepaired(5) ;
	dm1.guardGate() ;
	dm1.highFivesGuys() ;
	dm1.WhoAmI() ;

	std::cout << std::endl ;

	std::cout << dm1.getName() << " - " << dm2.getName() << " - " << dm3.getName() << std::endl << std::endl ;
	return 0 ;
}