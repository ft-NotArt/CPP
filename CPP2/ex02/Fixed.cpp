/* Includes */

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

float Fixed::operator+(const Fixed &to_add) {
	return (this->toFloat() + to_add.toFloat()) ;
}

float Fixed::operator-(const Fixed &to_add) {
	return (this->toFloat() - to_add.toFloat()) ;
}

float Fixed::operator*(const Fixed &to_add) {
	return (this->toFloat() * to_add.toFloat()) ;
}

float Fixed::operator/(const Fixed &to_add) {
	if (to_add.toFloat() == 0) {
		std::cout << "Apparently : \"If you ever do a division by 0, it is acceptable that the program crashes\", but not for me... (returning 0 btw)" << std::endl ;
		return 0 ;
	}
	return (this->toFloat() / to_add.toFloat()) ;
}

Fixed &Fixed::operator++() {
	this->raw++ ;
	return *this ;
}

Fixed Fixed::operator++(int) {
	Fixed ret = *this ;
	this->raw++ ;
	return ret ;
}

Fixed &Fixed::operator--() {
	this->raw-- ;
	return *this ;
}

Fixed Fixed::operator--(int) {
	Fixed ret = *this ;
	this->raw-- ;
	return ret ;
}

bool Fixed::operator==(const Fixed &to_cmp) {
	return (this->toFloat() == to_cmp.toFloat()) ;
}

bool Fixed::operator!=(const Fixed &to_cmp) {
	return (this->toFloat() != to_cmp.toFloat()) ;
}

bool Fixed::operator>(const Fixed &to_cmp) {
	return (this->toFloat() > to_cmp.toFloat()) ;
}

bool Fixed::operator>=(const Fixed &to_cmp) {
	return (this->toFloat() >= to_cmp.toFloat()) ;
}

bool Fixed::operator<(const Fixed &to_cmp) {
	return (this->toFloat() < to_cmp.toFloat()) ;
}

bool Fixed::operator<=(const Fixed &to_cmp) {
	return (this->toFloat() <= to_cmp.toFloat()) ;
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

Fixed &Fixed::min(Fixed &val1, Fixed &val2) {
	if (val1.toFloat() < val2.toFloat())
		return val1 ;
	return val2 ;
}

const Fixed &Fixed::min(Fixed const &val1, Fixed const &val2) {
	if (val1.toFloat() < val2.toFloat())
		return val1 ;
	return val2 ;
}

Fixed &Fixed::max(Fixed &val1, Fixed &val2) {
	if (val1.toFloat() > val2.toFloat())
		return val1 ;
	return val2 ;
}

const Fixed &Fixed::max(Fixed const &val1, Fixed const &val2) {
	if (val1.toFloat() > val2.toFloat())
		return val1 ;
	return val2 ;
}