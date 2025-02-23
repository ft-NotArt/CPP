#include "BitcoinExchange.hpp"
#include <map>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./BitcoinExchange <input_file>" << std::endl ;
		return 1 ;
	}

	std::ifstream datafile("data.csv") ;
	if (!datafile.is_open()) {
		std::cerr << "Error, can't open data.csv" << std::endl ;
		return 1 ;
	}

	std::ifstream infile(argv[1]) ;
	if (!infile.is_open()) {
		std::cerr << "Error, can't open file " << argv[1] << std::endl ;
		return 1 ;
	}

	try {
		BitcoinExchange data(datafile) ;
		data.showStocks(infile) ;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}
