#include "ScavTrap.hpp"
#include <iostream>

int main() {
	ScavTrap sv1 ;

	ScavTrap sv2("bouli", 5, 1200, 8795) ;

	ScavTrap sv3(sv2) ;

	std::cout << std::endl ;

	std::cout << sv1 << std::endl ;
	std::cout << sv2 << std::endl ;
	std::cout << sv3 << std::endl ;

	std::cout << std::endl ;
	sv3 = sv1 ;

	std::cout << sv1 << std::endl ;
	std::cout << sv2 << std::endl ;
	std::cout << sv3 << std::endl ;

	std::cout << std::endl ;

	sv1.attack("anenemythatseemsthreatening") ;
	sv1.takeDamage(5) ;
	sv1.beRepaired(5) ;
	sv1.guardGate() ;

	std::cout << std::endl ;

	return 0 ;
}