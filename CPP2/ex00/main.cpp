#include "Fixed.hpp"
#include <iostream>

int main() {
	Fixed a ;
	Fixed b(a) ;
	Fixed c ;
	c = b ;
	std::cout << a.getRawBits() << std::endl ;
	std::cout << b.getRawBits() << std::endl ;
	std::cout << c.getRawBits() << std::endl ;
	std::cout << std::endl ;
	a.setRawBits(2) ;
	std::cout << a.getRawBits() << std::endl ;
	std::cout << b.getRawBits() << std::endl ;
	std::cout << c.getRawBits() << std::endl ;
	std::cout << std::endl ;
	b = a ;
	std::cout << a.getRawBits() << std::endl ;
	std::cout << b.getRawBits() << std::endl ;
	std::cout << c.getRawBits() << std::endl ;
	std::cout << std::endl ;

	Fixed *d = new Fixed() ;
	std::cout << a.getRawBits() << std::endl ;
	std::cout << d->getRawBits() << std::endl ;
	std::cout << std::endl ;
	*d = a ;
	std::cout << a.getRawBits() << std::endl ;
	std::cout << d->getRawBits() << std::endl ;
	std::cout << std::endl ;
	d->setRawBits(4) ;
	a = *d ;
	std::cout << a.getRawBits() << std::endl ;
	std::cout << d->getRawBits() << std::endl ;
	std::cout << std::endl ;

	b = c = *d ;
	std::cout << a.getRawBits() << std::endl ;
	std::cout << b.getRawBits() << std::endl ;
	std::cout << c.getRawBits() << std::endl ;
	std::cout << d->getRawBits() << std::endl ;
	std::cout << std::endl ;


	delete d ;

	return 0 ;
}