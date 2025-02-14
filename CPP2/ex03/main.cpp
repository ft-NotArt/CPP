#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void bsp_show(Point const a, Point const b, Point const c, Point const point, bool expected) {
	std::cout << "\t Is " << point << " inside of triangle (" << a << ", " << b << ", " << c << ") ?" << std::endl ;
	std::cout << "\t BSP says : " << (bsp(a, b, c, point) ? "true" : "false") << std::endl ;
	std::cout << "\t It should says " << (expected ? "true" : "false") << std::endl << std::endl ;
}

int main() {
	std::cout << std::endl << "-- BASIC TESTS --" << std::endl <<std::endl ;
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, 3.0) ;
		Point c(3.0, 0.0) ;
		Point point(1.0, 1.0) ;

		bsp_show(a, b, c, point, true) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, 3.0) ;
		Point c(3.0, 0.0) ;
		Point point(4.0, 1.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, 3.0) ;
		Point c(3.0, 0.0) ;
		Point point(1.0, -1.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	std::cout << std::endl ;
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, -3.0) ;
		Point c(3.0, 0.0) ;
		Point point(1.0, -1.0) ;

		bsp_show(a, b, c, point, true) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, -3.0) ;
		Point c(3.0, 0.0) ;
		Point point(-1.0, -1.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, -3.0) ;
		Point c(3.0, 0.0) ;
		Point point(1.0, 1.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	std::cout << std::endl ;
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, 3.0) ;
		Point c(-3.0, 0.0) ;
		Point point(-1.0, 1.0) ;

		bsp_show(a, b, c, point, true) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, 3.0) ;
		Point c(-3.0, 0.0) ;
		Point point(-1.0, -1.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, 3.0) ;
		Point c(-3.0, 0.0) ;
		Point point(1.0, 1.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	std::cout << std::endl ;
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, -3.0) ;
		Point c(-3.0, 0.0) ;
		Point point(-1.0, -1.0) ;

		bsp_show(a, b, c, point, true) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, -3.0) ;
		Point c(-3.0, 0.0) ;
		Point point(1.0, -1.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, -3.0) ;
		Point c(-3.0, 0.0) ;
		Point point(1.0, 1.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	std::cout << std::endl << "-- ON EDGE/VERTEX TESTS --" << std::endl << std::endl ;
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, 3.0) ;
		Point c(3.0, 0.0) ;
		Point point(0.0, 0.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, 3.0) ;
		Point c(3.0, 0.0) ;
		Point point(0.0, 3.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, 3.0) ;
		Point c(3.0, 0.0) ;
		Point point(0.0, 0.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, 3.0) ;
		Point c(3.0, 0.0) ;
		Point point(2.0, 0.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, 3.0) ;
		Point c(3.0, 0.0) ;
		Point point(0.0, 2.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, 0.0) ;
		Point c(0.0, 0.0) ;
		Point point(0.0, 0.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	std::cout << std::endl << "-- FLAT TRIANGLE TESTS --" << std::endl << std::endl ;
	{
		Point a(0.0, 0.0) ;
		Point b(1.0, 0.0) ;
		Point c(3.0, 0.0) ;
		Point point(2.0, 0.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	{
		Point a(0.0, 0.0) ;
		Point b(0.0, 1.0) ;
		Point c(0.0, 3.0) ;
		Point point(0.0, 2.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	std::cout << std::endl << "-- LONG ASS TRIANGLE TESTS --" << std::endl << std::endl ;
	{
		Point a(2.0, -2.0) ;
		Point b(0.0, 3.0) ;
		Point c(4.0, 2.0) ;
		Point point(2.0, 0.0) ;

		bsp_show(a, b, c, point, true) ;
	}
	{
		Point a(2.0, -2.0) ;
		Point b(0.0, 3.0) ;
		Point c(4.0, 2.0) ;
		Point point(2.0, 3.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	{
		Point a(2.0, -2.0) ;
		Point b(0.0, 3.0) ;
		Point c(4.0, 2.0) ;
		Point point(0.5, 0.0) ;

		bsp_show(a, b, c, point, false) ;
	}
	return 0 ;
}
