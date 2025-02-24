#include "Iter.hpp"
#include <iostream>

void times_two(int &i) {
	i *= 2 ;
}

void const_times_two(const int &i) {
	std::cout << i ;
}

void str_trunc(std::string &str) {
	if (str.size() > 3)
		str.erase() ;
}

int main() {
	int int_array[5] = {0, 1, 2, 3, 4} ;

	for (size_t i = 0; i < 5; i++) {
		std::cout << int_array[i] << " " ;
	}
	std::cout << std::endl ;

	iter(int_array, 5, times_two) ;

	for (size_t i = 0; i < 5; i++) {
		std::cout << int_array[i] << " " ;
	}
	std::cout << std::endl ;

	iter(int_array, 3, times_two) ;

	for (size_t i = 0; i < 5; i++) {
		std::cout << int_array[i] << " " ;
	}
	std::cout << std::endl ;

	// ============================================== //

	const int const_int_array[5] = {0, 1, 2, 3, 4} ;

	for (size_t i = 0; i < 5; i++) {
		std::cout << const_int_array[i] << " " ;
	}
	std::cout << std::endl ;

	std::cout << "Iter: " ;
	iter(const_int_array, 5, const_times_two) ;
	std::cout << std::endl ;

	for (size_t i = 0; i < 5; i++) {
		std::cout << const_int_array[i] << " " ;
	}
	std::cout << std::endl ;

	std::cout << "Iter: " ;
	iter(const_int_array, 3, const_times_two) ;
	std::cout << std::endl ;

	for (size_t i = 0; i < 5; i++) {
		std::cout << const_int_array[i] << " " ;
	}
	std::cout << std::endl ;

	// ============================================== //

	std::cout << std::endl ;

	std::string str_array[5] = {"one", "two", "three", "four", "five"} ;

	for (size_t i = 0; i < 5; i++) {
		std::cout << str_array[i] << std::endl ;
	}
	std::cout << std::endl ;

	iter(str_array, 5, str_trunc) ;

	for (size_t i = 0; i < 5; i++) {
		std::cout << str_array[i] << std::endl ;
	}
	std::cout << std::endl ;
}
