/* Includes */

#include "RPN.hpp"


/* Constructors & Destructor */

RPN::RPN() {}

RPN::RPN(const RPN &cpy) { (void) cpy ; } // Won't be used

RPN::~RPN() {}


/* Operator overload */

RPN &RPN::operator=(const RPN &cpy) { (void) cpy ; return *this ; } // Won't be used


/* Method */

void RPN::calc(std::string line) {
	std::stringstream ss(line) ;

	char c ;
	ss >> c ;
	while (!ss.eof()) {
		if (isdigit(c)) {
			this->numbers.push(c - '0') ;
		} else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (this->numbers.size() < 2)
				throw RPN::TooFewNumbersException() ;

			int r_val = this->numbers.top() ;
			this->numbers.pop() ;
			int l_val = this->numbers.top() ;
			this->numbers.pop() ;

			switch (c) {
			case '+' :
				this->numbers.push(l_val + r_val) ; break ;
			case '-' :
				this->numbers.push(l_val - r_val) ; break ;
			case '*' :
				this->numbers.push(l_val * r_val) ; break ;
			case '/' :
				if (r_val == 0)
					throw RPN::DivisionByZeroException() ;
				this->numbers.push(l_val / r_val) ; break ;
			}
		} else
			throw RPN::WrongSymbolException() ;
		ss >> c ;
	}
	if (this->numbers.size() != 1)
		throw RPN::TooFewOperandsException() ;

	std::cout << this->numbers.top() << std::endl ;
}


/* Exceptions */

const char *RPN::WrongSymbolException::what() const throw() { return "WrongSymbolException: Authorized symbols are `+ - * /` and numbers between 0 and 9" ; }
const char *RPN::TooFewNumbersException::what() const throw() { return "TooFewNumbersException: Trying to do an operation with too few numbers" ; }
const char *RPN::TooFewOperandsException::what() const throw() { return "TooFewOperandsException: Trying to calculate a line with too few operands" ; }
const char *RPN::DivisionByZeroException::what() const throw() { return "DivisionByZeroException: Trying to do a division by zero" ; }
