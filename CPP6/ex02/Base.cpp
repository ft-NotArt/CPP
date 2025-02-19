/* Include */

#include "Base.hpp"


/* Destructor */

Base::~Base() {}


/* Functions */

Base *generate() {
	srand(time(NULL)) ;
	short rndm = rand() ;
	if ((rndm % 3) == 0)
		return new A ;
	if ((rndm % 3) == 1)
		return new B ;
	return new C ;
}

void identify(Base *ptr) {
	if (dynamic_cast<A *> (ptr)) {
		std::cout << "A" << std::endl ;
	} else if (dynamic_cast<B *> (ptr)) {
		std::cout << "B" << std::endl ;
	} else if (dynamic_cast<C *> (ptr)) {
		std::cout << "C" << std::endl ;
	}
}

void identify(Base &ref) {
	try {
		(void) dynamic_cast<A &> (ref) ;
		std::cout << "A" << std::endl ;
	} catch(const std::exception& e) {}
	try {
		(void) dynamic_cast<B &> (ref) ;
		std::cout << "B" << std::endl ;
	} catch(const std::exception& e) {}
	try {
		(void) dynamic_cast<C &> (ref) ;
		std::cout << "C" << std::endl ;
	} catch(const std::exception& e) {}
	return ;
}
