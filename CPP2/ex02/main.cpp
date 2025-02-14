#include "Fixed.hpp"
#include <iostream>

/* cauvray Main, huge thanks to him */

void	print_fixed(Fixed const &fixed) {
	std::cout	<< "-----[ FIXED ]-----" << std::endl
				<< "Value\t\t: " << fixed << std::endl
				<< "getRawBits()\t: " << fixed.getRawBits() << std::endl
				<< "toInt()\t\t: " << fixed.toInt() << std::endl
				<< "toFloat()\t: " << fixed.toFloat() << std::endl
				<< "-------------------" << std::endl;
}

int	main() {
	// Default tests from the subject
	{

		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}

	// Comparison tests
	{
		Fixed a(18.18f);
		Fixed b(42.42f);
		Fixed c(101.101f);

		print_fixed(a);
		print_fixed(b);
		print_fixed(c);

		std::cout	<< "Operator: >" << std::endl
					<< a << " > " << a << ": " << (a > a) << "\t"
					<< a << " > " << b << ": " << (a > b) << "\t"
					<< a << " > " << c << ": " << (a > c) << std::endl
					<< b << " > " << a << ": " << (b > a) << "\t"
					<< b << " > " << b << ": " << (b > b) << "\t"
					<< b << " > " << c << ": " << (b > c) << std::endl
					<< c << " > " << a << ": " << (c > a) << "\t"
					<< c << " > " << b << ": " << (c > b) << "\t"
					<< c << " > " << c << ": " << (c > c) << std::endl
					<< "Operator: <" << std::endl
					<< a << " < " << a << ": " << (a < a) << "\t"
					<< a << " < " << b << ": " << (a < b) << "\t"
					<< a << " < " << c << ": " << (a < c) << std::endl
					<< b << " < " << a << ": " << (b < a) << "\t"
					<< b << " < " << b << ": " << (b < b) << "\t"
					<< b << " < " << c << ": " << (b < c) << std::endl
					<< c << " < " << a << ": " << (c < a) << "\t"
					<< c << " < " << b << ": " << (c < b) << "\t"
					<< c << " < " << c << ": " << (c < c) << std::endl
					<< "Operator: >=" << std::endl
					<< a << " >= " << a << ": " << (a >= a) << "\t"
					<< a << " >= " << b << ": " << (a >= b) << "\t"
					<< a << " >= " << c << ": " << (a >= c) << std::endl
					<< b << " >= " << a << ": " << (b >= a) << "\t"
					<< b << " >= " << b << ": " << (b >= b) << "\t"
					<< b << " >= " << c << ": " << (b >= c) << std::endl
					<< c << " >= " << a << ": " << (c >= a) << "\t"
					<< c << " >= " << b << ": " << (c >= b) << "\t"
					<< c << " >= " << c << ": " << (c >= c) << std::endl
					<< "Operator: <=" << std::endl
					<< a << " <= " << a << ": " << (a <= a) << "\t"
					<< a << " <= " << b << ": " << (a <= b) << "\t"
					<< a << " <= " << c << ": " << (a <= c) << std::endl
					<< b << " <= " << a << ": " << (b <= a) << "\t"
					<< b << " <= " << b << ": " << (b <= b) << "\t"
					<< b << " <= " << c << ": " << (b <= c) << std::endl
					<< c << " <= " << a << ": " << (c <= a) << "\t"
					<< c << " <= " << b << ": " << (c <= b) << "\t"
					<< c << " <= " << c << ": " << (c <= c) << std::endl
					<< "Operator: ==" << std::endl
					<< a << " == " << a << ": " << (a == a) << "\t"
					<< a << " == " << b << ": " << (a == b) << "\t"
					<< a << " == " << c << ": " << (a == c) << std::endl
					<< b << " == " << a << ": " << (b == a) << "\t"
					<< b << " == " << b << ": " << (b == b) << "\t"
					<< b << " == " << c << ": " << (b == c) << std::endl
					<< c << " == " << a << ": " << (c == a) << "\t"
					<< c << " == " << b << ": " << (c == b) << "\t"
					<< c << " == " << c << ": " << (c == c) << std::endl
					<< "Operator: !=" << std::endl
					<< a << " != " << a << ": " << (a != a) << "\t"
					<< a << " != " << b << ": " << (a != b) << "\t"
					<< a << " != " << c << ": " << (a != c) << std::endl
					<< b << " != " << a << ": " << (b != a) << "\t"
					<< b << " != " << b << ": " << (b != b) << "\t"
					<< b << " != " << c << ": " << (b != c) << std::endl
					<< c << " != " << a << ": " << (c != a) << "\t"
					<< c << " != " << b << ": " << (c != b) << "\t"
					<< c << " != " << c << ": " << (c != c) << std::endl;
	}

	// Arithmetic tests
	{
		Fixed a(18.18f);
		Fixed b(42.42f);
		Fixed c(101.101f);

		print_fixed(a);
		print_fixed(b);
		print_fixed(c);

		std::cout	<< "Operator: +" << std::endl
					<< a << " + " << a << ": " << (a + a) << "\t"
					<< a << " + " << b << ": " << (a + b) << "\t"
					<< a << " + " << c << ": " << (a + c) << std::endl
					<< b << " + " << a << ": " << (b + a) << "\t"
					<< b << " + " << b << ": " << (b + b) << "\t"
					<< b << " + " << c << ": " << (b + c) << std::endl
					<< c << " + " << a << ": " << (c + a) << "\t"
					<< c << " + " << b << ": " << (c + b) << "\t"
					<< c << " + " << c << ": " << (c + c) << std::endl
					<< "Operator: -" << std::endl
					<< a << " - " << a << ": " << (a - a) << "\t\t"
					<< a << " - " << b << ": " << (a - b) << "\t"
					<< a << " - " << c << ": " << (a - c) << std::endl
					<< b << " - " << a << ": " << (b - a) << "\t"
					<< b << " - " << b << ": " << (b - b) << "\t\t"
					<< b << " - " << c << ": " << (b - c) << std::endl
					<< c << " - " << a << ": " << (c - a) << "\t"
					<< c << " - " << b << ": " << (c - b) << "\t"
					<< c << " - " << c << ": " << (c - c) << std::endl
					<< "Operator: *" << std::endl
					<< a << " * " << a << ": " << (a * a) << "\t"
					<< a << " * " << b << ": " << (a * b) << "\t"
					<< a << " * " << c << ": " << (a * c) << std::endl
					<< b << " * " << a << ": " << (b * a) << "\t"
					<< b << " * " << b << ": " << (b * b) << "\t"
					<< b << " * " << c << ": " << (b * c) << std::endl
					<< c << " * " << a << ": " << (c * a) << "\t\t"
					<< c << " * " << b << ": " << (c * b) << "\t"
					<< c << " * " << c << ": " << (c * c) << std::endl
					<< "Operator: /" << std::endl
					<< a << " / " << a << ": " << (a / a) << "\t\t"
					<< a << " / " << b << ": " << (a / b) << "\t"
					<< a << " / " << c << ": " << (a / c) << std::endl
					<< b << " / " << a << ": " << (b / a) << "\t"
					<< b << " / " << b << ": " << (b / b) << "\t\t"
					<< b << " / " << c << ": " << (b / c) << std::endl
					<< c << " / " << a << ": " << (c / a) << "\t"
					<< c << " / " << b << ": " << (c / b) << "\t"
					<< c << " / " << c << ": " << (c / c) << std::endl
					<< a << " / 0 : " << (a / 0) << std::endl;
	}

	// Increment / Decrement tests
	{
		Fixed a(18);
		Fixed b(42);
		Fixed c(100);

		print_fixed(a);
		print_fixed(b);
		print_fixed(c);

		std::cout	<< "Operator: pre-increment (++)" << std::endl
					<< "a: " << a << "\t"
					<< "++a: " << ++a << "\t"
					<< "a après: " << a << std::endl
					<< "b: " << b << "\t"
					<< "++b: " << ++b << "\t"
					<< "b après: " << b << std::endl
					<< "c: " << c << "\t"
					<< "++c: " << ++c << "\t"
					<< "c après: " << c << std::endl
					<< "Operator: post-increment (++)" << std::endl
					<< "a: " << a << "\t"
					<< "a++: " << a++ << "\t"
					<< "a après: " << a << std::endl
					<< "b: " << b << "\t"
					<< "b++: " << b++ << "\t"
					<< "b après: " << b << std::endl
					<< "c: " << c << "\t"
					<< "c++: " << c++ << "\t"
					<< "c après: " << c << std::endl
					<< "Operator: pre-decrement (--)" << std::endl
					<< "a: " << a << "\t"
					<< "--a: " << --a << "\t"
					<< "a après: " << a << std::endl
					<< "b: " << b << "\t"
					<< "--b: " << --b << "\t"
					<< "b après: " << b << std::endl
					<< "c: " << c << "\t"
					<< "--c: " << --c << "\t"
					<< "c après: " << c << std::endl
					<< "Operator: post-decrement (--)" << std::endl
					<< "a: " << a << "\t"
					<< "a--: " << a-- << "\t"
					<< "a après: " << a << std::endl
					<< "b: " << b << "\t"
					<< "b--: " << b-- << "\t"
					<< "b après: " << b << std::endl
					<< "c: " << c << "\t"
					<< "c--: " << c-- << "\t"
					<< "c après: " << c << std::endl;
	}

	// Min / Max tests
	{
		Fixed a(18);
		Fixed b(42);
		Fixed c(100);

		print_fixed(a);
		print_fixed(b);
		print_fixed(c);

		std::cout	<< "Operator: min" << std::endl
					<< "min(" << a << ", " << b << "): " << Fixed::min(a, b) << "\t\t"
					<< "min(" << a << ", " << c << "): " << Fixed::min(a, c) << "\t"
					<< "min(" << b << ", " << c << "): " << Fixed::min(b, c) << std::endl
					<< "min(" << b << ", " << a << "): " << Fixed::min(b, a) << "\t\t"
					<< "min(" << c << ", " << a << "): " << Fixed::min(c, a) << "\t"
					<< "min(" << c << ", " << b << "): " << Fixed::min(c, b) << std::endl
					<< "Operator: max" << std::endl
					<< "max(" << a << ", " << b << "): " << Fixed::max(a, b) << "\t\t"
					<< "max(" << a << ", " << c << "): " << Fixed::max(a, c) << "\t"
					<< "max(" << b << ", " << c << "): " << Fixed::max(b, c) << std::endl
					<< "max(" << b << ", " << a << "): " << Fixed::max(b, a) << "\t\t"
					<< "max(" << c << ", " << a << "): " << Fixed::max(c, a) << "\t"
					<< "max(" << c << ", " << b << "): " << Fixed::max(c, b) << std::endl;
	}
	return 0;
}
