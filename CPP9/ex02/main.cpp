#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>

static bool str_isdigit(std::string val) {
	for (size_t i = 0; val[i]; i++) {
		if (!isdigit(val[i]))
			return false ;
	}
	return true ;
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cerr << "Usage: ./PmergeMe <uint> <uint> <uint> ... <uint> (no duplicates)" << std::endl ;
		return 1 ;
	}

	int array[argc - 1] ;
	for (int i = 1; i < argc; i++) {
		if (!str_isdigit(argv[i])) {
			std::cerr << "Error: Please only use positive numbers as input" << std::endl ;
			return 1 ;
		}
		array[i - 1] = atoi(argv[i]) ;
	}

	for (int i = 0; i < argc - 1; i++) {
		for (int j = i + 1; j < argc - 1; j++) {
			if (array[i] == array[j]) {
				std::cerr << "Error: Please don't use duplicates" << std::endl ;
				return 1 ;
			}
		}
	}

	std::vector<unsigned int> pmVector ;
	std::deque<unsigned int> pmDeque ;
	for (int i = 0; i < (argc - 1); i++) {
		pmVector.push_back(array[i]) ;
		pmDeque.push_back(array[i]) ;
	}

	PmergeMe merge(pmVector, pmDeque) ;
	struct timeval before ;
	struct timeval after ;

	std::cout << "Before:\t" ;
	merge.printVector() ;

	gettimeofday(&before, NULL) ;
	merge.pmVector = sortVector(merge.pmVector) ;
	gettimeofday(&after, NULL) ;

	std::cout << "After:\t" ;
	merge.printVector() ;

	std::cout << "Time to sort a range of\t" << merge.pmVector.size() << " elements using std::vector\t: " ;
	std::cout << ((double) (after.tv_usec - before.tv_usec)) / 1000000 << " us" << std::endl ;

	gettimeofday(&before, NULL) ;
	merge.pmDeque = sortDeque(merge.pmDeque) ;
	gettimeofday(&after, NULL) ;


	std::cout << "Time to sort a range of\t" << merge.pmDeque.size() << " elements using std::deque\t: " ;
	std::cout << ((double) (after.tv_usec - before.tv_usec)) / 1000000 << " us" << std::endl ;
}
