#pragma once

#include <string>

class Fixed
{
private:
	static const int fracBits = 8 ;
	int raw ;
public:
	Fixed() ;
	Fixed(Fixed const &to_cpy) ;
	~Fixed() ;
	Fixed &operator=(const Fixed &to_cpy) ;
	void setRawBits(int const raw) ;
	int getRawBits() const ;
};
