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
	float operator+(const Fixed &to_add) ;
	float operator-(const Fixed &to_add) ;
	float operator*(const Fixed &to_add) ;
	float operator/(const Fixed &to_add) ;
	Fixed &operator++() ; // Pre-increment
	Fixed operator++(int) ; // Post-increment
	Fixed &operator--() ; // Pre-increment
	Fixed operator--(int) ; // Post-increment
	bool operator==(const Fixed &to_cmp) ;
	bool operator!=(const Fixed &to_cmp) ;
	bool operator>(const Fixed &to_cmp) ;
	bool operator>=(const Fixed &to_cmp) const ;
	bool operator<(const Fixed &to_cmp) ;
	bool operator<=(const Fixed &to_cmp) const ;
	void setRawBits(int const raw) ;
	int getRawBits() const ;
	float toFloat() const ;
	int toInt() const ;
	static Fixed &min(Fixed &val1, Fixed &val2) ;
	static const Fixed &min(const Fixed &val1, const Fixed &val2) ;
	static Fixed &max(Fixed &val1, Fixed &val2) ;
	static const Fixed &max(const Fixed &val1, const Fixed &val2) ;
};

std::ostream &operator<<(std::ostream &out, const Fixed &to_stream) ;
