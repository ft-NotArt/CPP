#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <limits>
#include <ios>
#include <cstdlib>
#include <ctime>
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <exception>

class BitcoinExchange
{
private:
	std::map<std::string, double> BTC_prices ;
public:
	BitcoinExchange() ;
	BitcoinExchange(std::ifstream &file) ;
	BitcoinExchange(const BitcoinExchange &cpy) ;
	~BitcoinExchange() ;

	BitcoinExchange &operator=(const BitcoinExchange &cpy) ;

	void showStocks(std::ifstream &file) ;

	class NoCommaException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;
	class InvalidDateException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;
	class InvalidValueException : public std::exception {
		public:
			virtual const char *what() const throw() ;
	} ;
} ;

bool str_isvaliddate(std::string date) ;
bool str_isdigit(std::string val) ;
bool str_isdouble(std::string val) ;
int dateToInt(std::string date) ;
std::string dateToStr(int date) ;
