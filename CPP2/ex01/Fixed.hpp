#pragma once

#include <string>
#include <cmath>
#include <iostream>

class Fixed
{
private:
	static const int fracBits = 8 ;
	int raw ;
public:
	Fixed() ;
	Fixed(int const raw) ;
	Fixed(float const raw) ;
	Fixed(Fixed const &to_cpy) ;
	~Fixed() ;
	Fixed &operator=(const Fixed &to_cpy) ;
	void setRawBits(int const raw) ;
	int getRawBits() const ;
	float toFloat() const ;
	int toInt() const ;
};

std::ostream &operator<<(std::ostream &out, const Fixed &to_stream) ;
