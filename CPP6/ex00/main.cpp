#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "You're being selfish..." << std::endl ;
		return 1 ;
	} else if (argc > 2) {
		std::cout << "You're being greedy !" << std::endl ;
		return 1 ;
	}
	ScalarConverter::convert(argv[1]) ;

	return 0 ;
}