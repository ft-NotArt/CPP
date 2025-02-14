#pragma once

#include "Fixed.hpp"
#include <string>

class Point
{
private:
	const Fixed x ;
	const Fixed y ;
public:
	Point() ;
	Point(float const x, float const y) ;
	Point(Point const &to_cpy) ;
	Point &operator=(const Point &to_cpy) ;
	~Point() ;
	const Fixed &getX() const ;
	const Fixed &getY() const ;
};

std::ostream &operator<<(std::ostream &out, const Point &to_stream) ;
