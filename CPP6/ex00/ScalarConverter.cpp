/* Includes */

#include "ScalarConverter.hpp"


/* Constructors & Destructor */

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void) copy ; }

ScalarConverter::~ScalarConverter() {}


/* Operator overload */

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) { (void) copy ; return *this ; }


/* Method */

static bool str_isliteral(const char *str) {
	bool found_dot = false ;
	for (size_t i = 0; str[i]; i++) {
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			return false ;
		if (str[i] == '.') {
			if (found_dot)
				return false ;
			else
				found_dot = true ;
		}
		if (str[i] == 'f' && str[i + 1])
			return false ;
	}
	return true ;
}

static void display(std::string charstr, std::string intstr, std::string floatstr, std::string doublestr) {
	std::cout	<< "char: "		<< charstr		<<std::endl
				<< "int: "		<< intstr		<< std::endl
				<< "float: "	<< floatstr		<< std::endl
				<< "double: "	<< doublestr	<< std::endl ;
}

void ScalarConverter::convert(std::string str) {
	if (str == "nan" || str == "nanf") {
		display("impossible", "impossible", "nanf", "nan") ;
		return ;
	} else if (str == "inf" || str == "+inf" || str == "inff" || str == "+inff") {
		display("impossible", "impossible", "+inff", "+inf") ;
		return ;
	} else if (str == "-inf" || str == "-inff") {
		display("impossible", "impossible", "-inff", "-inf") ;
		return ;
	}

	if (!str_isliteral(str.c_str())) {
		std::cout << "Please pass 'a string representation of a C++ literal' as parameter" << std::endl ;
		return ;
	}

	char c ;
	int i ;
	float f ;
	double d ;

	if (str[str.size() - 1] == 'f') {					// An 'f' at the end of the string means float
		f = atof(str.c_str()) ;
		i = static_cast<int> (f) ;
		c = i ;
		d = static_cast<double> (f) ;
	} else if (str.find('.') == std::string::npos) {	// No '.' means integer
		i = atoi(str.c_str()) ;
		c = i ;
		f = static_cast<float> (i) ;
		d = static_cast<double> (i) ;
	} else {											// Remaining case is then double
		d = strtod(str.c_str(), NULL) ;
		i = static_cast<int> (d) ;
		c = i ;
		f = static_cast<float> (d) ;
	}


	std::string charstr ;
	std::string intstr ;
	std::string floatstr ;
	std::string doublestr ;
	std::stringstream ss ;

	if (isprint(c)) {
		charstr = std::string(3, c) ;
		charstr[0] = '\'' ;
		charstr[2] = '\'' ;
	}
	else
		charstr = "impossible" ;

	ss << i ;
	intstr = ss.str() ;
	ss.str("") ;

	ss << f << 'f' ;
	floatstr = ss.str() ;
	ss.str("") ;
	if (floatstr.find('.') == std::string::npos) {
		ss << f << ".0" << 'f' ;
		floatstr = ss.str() ;
		ss.str("") ;
	}

	ss << d ;
	doublestr = ss.str() ;
	ss.str("") ;
	if (doublestr.find('.') == std::string::npos) {
		ss << d << ".0" ;
		doublestr = ss.str() ;
		ss.str("") ;
	}


	display(charstr, intstr, floatstr, doublestr) ;
}