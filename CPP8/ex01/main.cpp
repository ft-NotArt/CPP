#include "Span.hpp"
#include <iostream>

#include <vector>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl ;

	Span sp2 = Span(10) ;

	std::vector<int> vect ;
	vect.push_back(6) ;
	vect.push_back(3) ;
	vect.push_back(17) ;
	vect.push_back(9) ;
	vect.push_back(11) ;

	sp2.addRange(vect.begin(), vect.end()) ;

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try {
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
		sp2.addNumber(5) ;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}