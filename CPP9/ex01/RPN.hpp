#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <exception>

class RPN
{
private:
	std::stack<int> numbers ;
public:
	RPN() ;
	RPN(const RPN &cpy) ;
	~RPN() ;

	RPN &operator=(const RPN &cpy) ;

	void calc(std::string line) ;

	class WrongSymbolException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;
	class TooFewNumbersException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;
	class TooFewOperandsException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;
	class DivisionByZeroException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;
} ;
