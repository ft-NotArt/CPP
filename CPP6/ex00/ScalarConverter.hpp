#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

class ScalarConverter
{
private:
	ScalarConverter() ;
	ScalarConverter(const ScalarConverter &copy) ;
	ScalarConverter &operator=(const ScalarConverter &copy) ;
public:
	~ScalarConverter() ;
	static void convert(std::string str) ;
};
