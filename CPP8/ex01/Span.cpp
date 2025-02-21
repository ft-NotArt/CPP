/* Includes */

#include "Span.hpp"


/* Constructor & Destructor */

Span::Span() : max_val(0) {}

Span::Span(unsigned int N) : max_val(N) {}

Span::Span(const Span &cpy) : max_val(cpy.max_val) {
	this->values = cpy.values ;
}

Span::~Span() {}


/* Operator overload */

Span &Span::operator=(const Span &cpy) {
	this->max_val = cpy.max_val ;
	this->values = cpy.values ;
	return *this ;
}


/* Methods */

void Span::addRange() {
	this->values.resize(this->max_val) ;
	std::fill(this->values.begin(), this->values.end(), 1) ;
}

void Span::addRange(std::vector<int>::iterator from, std::vector<int>::iterator to) {
	try {
		while (from != to) {
			this->addNumber(*from) ;
			from++ ;
		}
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}

void Span::addNumber(int number) {
	if (this->values.size() >= this->max_val)
		throw Span::SpanFullException() ;
	this->values.push_back(number) ;
}

unsigned int Span::shortestSpan() {
	if (this->values.size() == 0 || this->values.size() == 1)
		throw Span::SpanEmptyException() ;

	unsigned int shortest_span = abs(this->values[0] - this->values[1]) ;

	for (size_t i = 0; i < this->values.size(); i++) {
		for (size_t j = (i + 1); j < this->values.size(); j++) {
			if ((unsigned int) abs(this->values[i] - this->values[j]) < shortest_span)
				shortest_span = abs(this->values[i] - this->values[j]) ;
		}
	}

	return shortest_span ;
}

unsigned int Span::longestSpan() {
	if (this->values.size() == 0 || this->values.size() == 1)
		throw Span::SpanEmptyException() ;

	unsigned int longestSpan = abs(this->values[0] - this->values[1]) ;

	for (size_t i = 0; i < this->values.size(); i++) {
		for (size_t j = (i + 1); j < this->values.size(); j++) {
			if ((unsigned int) abs(this->values[i] - this->values[j]) > longestSpan)
				longestSpan = abs(this->values[i] - this->values[j]) ;
		}
	}

	return longestSpan ;
}


/* Exception */

const char *Span::SpanFullException::what() const throw() { return "SpanFullException : can't take more numbers" ; }
const char *Span::SpanEmptyException::what() const throw() { return "SpanEmptyException : too few numbers" ; }
