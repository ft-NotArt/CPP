#include "FragTrap.hpp"
#include <iostream>

int main() {
	FragTrap fg1 ;

	FragTrap fg2("bouli", 5, 1200, 8795) ;

	FragTrap fg3(fg2) ;

	std::cout << std::endl ;

	std::cout << fg1 << std::endl ;
	std::cout << fg2 << std::endl ;
	std::cout << fg3 << std::endl ;

	std::cout << std::endl ;
	fg3 = fg1 ;

	std::cout << fg1 << std::endl ;
	std::cout << fg2 << std::endl ;
	std::cout << fg3 << std::endl ;

	std::cout << std::endl ;

	fg1.attack("anenemythatseemsthreatening") ;
	fg1.takeDamage(5) ;
	fg1.beRepaired(5) ;
	fg1.highFivesGuys() ;

	std::cout << std::endl ;

	return 0 ;
}