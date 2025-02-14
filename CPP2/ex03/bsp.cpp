#include "Point.hpp"

// From my libft
static long long	ft_abs(int nb)
{
	return (((long long) nb * (1 + ((nb < 0) * (-2)))));
}

static float area(const Point &p1, const Point &p2, const Point &p3) {
	return (ft_abs(	p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())
				+	p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())
				+	p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat()))
			/ 2.0) ;
}

static bool is_on_line(const Point &a, const Point &b, const Point &point) {
	return !(	point.getX().toFloat() * (b.getY().toFloat() - a.getY().toFloat())
			+	point.getY().toFloat() * (a.getX().toFloat() - b.getX().toFloat())
			+	(b.getX().toFloat() * a.getY().toFloat() - a.getX().toFloat() * b.getY().toFloat())) ;
}

static bool is_on_segment(const Point &a, const Point &b, const Point &point) {
	return (	is_on_line(a, b, point)
			&&	point.getX() >= Fixed::min(a.getX(), b.getX())
			&&	point.getX() <= Fixed::max(a.getX(), b.getX())
			&&	point.getY() >= Fixed::min(a.getY(), b.getY())
			&&	point.getY() <= Fixed::max(a.getY(), b.getY())) ;
}

// En gros on part pas sur un BSP
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float Area = area(a, b, c) ;
	float Area1 = area(point, b, c) ;
	float Area2 = area(a, point, c) ;
	float Area3 = area(a, b, point) ;

	return (Area == (Area1 + Area2 + Area3)
		&& !is_on_segment(a, b, point)
		&& !is_on_segment(b, c, point)
		&& !is_on_segment(a, c, point)) ;
}