/* Includes */

#include "Point.hpp"


/* Constructors and Destructor */

Point::Point() {}

Point::Point(float const x, float const y) : x(x), y(y) {}

Point::Point(Point const &to_cpy) : x(to_cpy.x), y(to_cpy.y) {}

Point::~Point() {}


/* Operator overloads */

Point &Point::operator=(const Point &to_cpy) { // Unusefull shit just for Orthodox Canonical Form
	(void) to_cpy ;
	return *this ;
}


std::ostream &operator<<(std::ostream &out, const Point &to_stream) {
	out << "x:" << to_stream.getX().toFloat() << " y:" << to_stream.getY().toFloat() ;
	return out ;
}


/* Set and Get */

const Fixed &Point::getX() const { return this->x ; }
const Fixed &Point::getY() const { return this->y ; }
