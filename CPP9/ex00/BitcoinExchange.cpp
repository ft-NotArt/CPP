/* Include */

#include "BitcoinExchange.hpp"


/* Constructors & Destructor */

BitcoinExchange::BitcoinExchange() {} // Won't be used

BitcoinExchange::BitcoinExchange(std::ifstream &file) {
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ;

	std::string str ;
	while (getline(file, str)) {
		size_t pos = str.find(',') ;

		if (pos == std::string::npos)
			throw BitcoinExchange::NoCommaException() ;

		std::string date = str.substr(0, pos) ;
		if (!str_isvaliddate(date))
			throw BitcoinExchange::InvalidDateException() ;

		std::string val  = str.substr(pos + 1) ;
		if (val == "" || !str_isdouble(val))
			throw BitcoinExchange::InvalidValueException() ;

		this->BTC_prices[date] = atof(val.c_str()) ;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) { // Won't be used
	this->BTC_prices = cpy.BTC_prices ;
}

BitcoinExchange::~BitcoinExchange() {}


/* Operator overload */

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy) { // Won't be used
	this->BTC_prices = cpy.BTC_prices ;
	return *this ;
}


/* Exceptions */

const char *BitcoinExchange::NoCommaException::what() const throw() { return "NoCommaException: missing a ',' on a line" ; }
const char *BitcoinExchange::InvalidDateException::what() const throw() { return "InvalidDateException: expected a date at format (YYYY-MM-DD)" ; }
const char *BitcoinExchange::InvalidValueException::what() const throw() { return "InvalidValueException: expected a value of type (double)" ; }


/* Method */

void BitcoinExchange::showStocks(std::ifstream &file) {
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ;

	std::string str ;
	while (getline(file, str)) {
		size_t pos = str.find('|') ;

		if (pos == std::string::npos) {
			std::cout << "Invalid input: " << str << std::endl ;
			continue ;
		}

		std::string date = str.substr(0, pos) ;
		// boost::trim(date) ;
		date = trim(date) ;
		if (!str_isvaliddate(date)) {
			std::cout << "Invalid date: " << date << std::endl ;
			continue ;
		}

		std::string val  = str.substr(pos + 1) ;
		// boost::trim(val) ;
		val = trim(val) ;
		if (val == "" || !str_isdouble(val) || atof(val.c_str()) > 1000) {
			std::cout << "Invalid val: " << val << std::endl ;
			continue ;
		}

		int intDate = dateToInt(date) ;
		while (this->BTC_prices.find(dateToStr(intDate)) == this->BTC_prices.end()) {
			intDate-- ;
		}

		std::cout << "In " << date << ", " << val << " would have cost " << atof(val.c_str()) * this->BTC_prices[dateToStr(intDate)] << std::endl ;
	}
}


/* Functions */

std::string trim_left(const std::string& str) {
	std::size_t index = str.find_first_not_of(PATTERN) ;

	if (index == std::string::npos)
		return "" ;

	return str.substr(index) ;
}

std::string trim_right(const std::string& str) {
	return str.substr(0,str.find_last_not_of(PATTERN) + 1);
}

std::string trim(const std::string& str) {
	return trim_left(trim_right(str));
}

bool isvalidday(int year, int month, int day) {
	if (day <= 0)
		return false ;

	if (month == 2) { // February
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) { // leap years
			if (day > 29)
				return false ;
		} else {
			if (day > 28)
				return false ;
		}
	} else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) { // 31 days months
		if (day > 31)
			return false ;
	} else {
		if (day > 30)
			return false ;
	}

	return true ;
}

bool str_isvaliddate(std::string date) { // This function alone is a lot... but its name is sufficient, only unspecified trick it does is invalidate dates from under Bitcoin creation
	size_t first_dash  = date.find('-') ;
	if (first_dash == std::string::npos)
		return false ;

	size_t second_dash = date.find('-', first_dash + 1) ;
	if (second_dash == std::string::npos)
		return false ;

	std::string str_year = date.substr(0, first_dash) ;
	if (!str_isdigit(str_year) || str_year.length() != 4)
		return false ;

	std::string str_month = date.substr(first_dash + 1, (second_dash) - (first_dash + 1)) ;
	if (!str_isdigit(str_month) || str_month.length() != 2)
		return false ;

	std::string str_day = date.substr(second_dash + 1) ;
	if (!str_isdigit(str_day) || str_day.length() != 2)
		return false ;

	int year = atoi(str_year.c_str()) ;
	if (year < 2009)
		return false ;
	int month = atoi(str_month.c_str()) ;
	if (month == 0 || month > 12)
		return false ;
	int day = atoi(str_day.c_str()) ;
	if (!isvalidday(year, month, day) || (year == 2009 && month == 01 && day < 2))
		return false ;

	std::tm tm ;
	bzero(&tm, sizeof(std::tm)) ;
	tm.tm_year = year - 1900 ;
	tm.tm_mon = month - 1 ;
	tm.tm_mday = month ;
	if (std::mktime(&tm) == -1) // This thing's shitty and will actually only be a last check just in case
		return false ;

	return true ;
}

bool str_isdigit(std::string val) {
	for (size_t i = 0; val[i]; i++) {
		if (!isdigit(val[i]))
			return false ;
	}
	return true ;
}

bool str_isdouble(std::string val) {
	for (size_t i = 0; val[i]; i++) {
		if (!isdigit(val[i]) && val[i] != '.')
			return false ;
	}
	return true ;
}

int dateToInt(std::string date) {
	size_t dash  = date.find('-') ;
	date.erase(dash, 1) ;

	dash = date.find('-') ;
	date.erase(dash, 1) ;

	return atoi(date.c_str()) ;
}


std::string dateToStr(int date) {
	std::stringstream ss ;
	ss << date ;

	std::string res ;
	res = ss.str() ;

	res.insert(4, "-") ;
	res.insert(7, "-") ;

	return res ;
}
