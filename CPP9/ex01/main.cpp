#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./RPN <RPN notation>" << std::endl ;
		return 1 ;
	}

	RPN rpn ;
	try {
		rpn.calc(argv[1]) ;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}