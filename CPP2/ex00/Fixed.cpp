#include "Fixed.hpp"

Fixed::Fixed() {
	this->raw = 0 ;
}

Fixed::Fixed(Fixed &to_cpy) {
	this->raw = to_cpy.raw ;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &to_cpy) {
	this->raw = to_cpy.raw ;
	return *this ;
}

void Fixed::setRawBits(int const raw) { this->raw = raw ; }

int Fixed::getRawBits() const { return this->raw ; }