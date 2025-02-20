#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main() {
	std::vector<int> a ;
	a.push_back(1) ;
	a.push_back(2) ;
	a.push_back(3) ;
	std::cout << "0 " << (easyfind(a, 0) ? "" : "not ") << "found in a" << std::endl ;
	std::cout << "1 " << (easyfind(a, 1) ? "" : "not ") << "found in a" << std::endl ;
	std::cout << "2 " << (easyfind(a, 2) ? "" : "not ") << "found in a" << std::endl ;
	std::cout << "3 " << (easyfind(a, 3) ? "" : "not ") << "found in a" << std::endl ;
	std::cout << "4 " << (easyfind(a, 4) ? "" : "not ") << "found in a" << std::endl ;
}
