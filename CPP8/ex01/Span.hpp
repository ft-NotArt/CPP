#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

class Span
{
private:
	std::vector<int> values ;
	unsigned int max_val ;
public:
	Span() ;
	Span(unsigned int N) ;
	Span(const Span &cpy) ;
	~Span() ;

	Span &operator=(const Span &cpy) ;

	void			addRange() ;
	void			addRange(std::vector<int>::iterator from, std::vector<int>::iterator to) ;
	void			addNumber(int number) ;
	unsigned int	shortestSpan() ;
	unsigned int	longestSpan() ;

	class SpanFullException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	};
	class SpanEmptyException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	};
};
