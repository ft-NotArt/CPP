#include "Base.hpp"
#include <iostream>

int main() {
	Base *base = generate() ;

	for (size_t i = 0; i < 100; i++) {
		identify(base) ;
		identify(*base) ;
		std::cout << std::endl ;
	}

	delete base ;
}