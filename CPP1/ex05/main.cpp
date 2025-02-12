#include "Harl.hpp"

int main() {
	Harl programer ;

	programer.complain("INFO") ;
	std::cout << std::endl ;
	programer.complain("DEBUG") ;
	std::cout << std::endl ;
	programer.complain("ERROR") ;
	std::cout << std::endl ;
	programer.complain("WARNING") ;
	std::cout << std::endl ;
	programer.complain("blablou") ;
	std::cout << std::endl ;
	programer.complain("E") ;
	std::cout << std::endl ;
	programer.complain("I") ;
	std::cout << std::endl ;
	programer.complain("W") ;
	std::cout << std::endl ;
	programer.complain("D") ;
	std::cout << std::endl ;
	programer.complain("") ;
	std::cout << std::endl ;
}