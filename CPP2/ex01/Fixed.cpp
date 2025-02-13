#include "Fixed.hpp"

/* Constructors and Destructor */
Fixed::Fixed() {
	this->raw = 0 ;
}

Fixed::Fixed(int const raw) {
	this->raw = (int) (roundf(raw * (1 << this->fracBits))) ;
}

Fixed::Fixed(float const raw) {
	this->raw = (int) (roundf(raw * (1 << this->fracBits))) ;
}

Fixed::Fixed(Fixed const &to_cpy) {
	this->raw = to_cpy.raw ;
}

Fixed::~Fixed() {}

/* Operator overloads */
Fixed &Fixed::operator=(const Fixed &to_cpy) {
	this->raw = to_cpy.raw ;
	return *this ;
}

std::ostream &operator<<(std::ostream &out, const Fixed &to_stream) {
	out << to_stream.toFloat() ;
	return out ;
}

/* Set and Get */
void Fixed::setRawBits(int const raw) { this->raw = raw ; }

int Fixed::getRawBits() const { return this->raw ; }

/* Methods */
float Fixed::toFloat() const {
	return (((float) this->raw) / ((float) (1 << this->fracBits))) ;
}

int Fixed::toInt() const {
	return ((int) ((float) this->raw) / ((float) (1 << this->fracBits))) ;
}
