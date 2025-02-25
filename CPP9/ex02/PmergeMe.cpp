/* Include */

#include "PmergeMe.hpp"


/* Constructors & Destructors */

PmergeMe::PmergeMe() {} // Won't be used

PmergeMe::PmergeMe(const PmergeMe &cpy) { // Won't be used
	this->pmVector = cpy.pmVector ;
	this->pmDeque = cpy.pmDeque ;
}

PmergeMe::PmergeMe(std::vector<unsigned int> &pmVector, std::deque<unsigned int> &pmDeque) {
	this->pmVector = pmVector ;
	this->pmDeque = pmDeque ;
}

PmergeMe::~PmergeMe() {}


/* Operator overloads */

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy) { // Won't be used
	this->pmVector = cpy.pmVector ;
	this->pmDeque = cpy.pmDeque ;
	return *this ;
}


/* Methods */

void PmergeMe::printVector() {
	for (int i = 0; i < (int) this->pmVector.size(); i++) {
		std::cout << this->pmVector[i] << " " ;
	}
	std::cout << std::endl ;
}


/* Functions */

std::vector<unsigned int> sortVector(std::vector<unsigned int> pmVector) {

	/* Get the number of pairs we'll create */
	int nb_pairs = (pmVector.size() / 2) ;

	/* Isolating the greater value to the end in case of odd number of value */
	unsigned int max ;
	if (pmVector.size() % 2) {
		max = *std::max_element(pmVector.begin(), pmVector.end()) ;
		std::vector<unsigned int>::iterator max_pos = getPosOf(pmVector, max) ;
		pmVector.erase(max_pos) ;
		pmVector.push_back(max) ;
	}

	/* Making pairs of value */
	std::pair<unsigned int *, unsigned int *> pairs[nb_pairs] ;
	for (int i = 0; i < nb_pairs * 2; i += 2) {
		pairs[i / 2] = std::make_pair(&pmVector[i], &pmVector[i + 1]) ;

		/* Sorting each pairs individually */
		if (*pairs[i / 2].first > *pairs[i / 2].second)
			std::swap(*pairs[i / 2].first, *pairs[i / 2].second) ;
	}

	/* Base case of the recursion */
	if (pmVector.size() <= 3)
		return pmVector ;

	/* Insert greater (right) values of pairs into r_values */
	std::vector<unsigned int> r_values ;
	for (int i = 0; i < nb_pairs; i++) {
		r_values.push_back(*pairs[i].second) ;
	}

	/* Recursively sort greater (right) values of pairs */
	r_values = sortVector(r_values) ;

	/* Fill sorted vector with first l_value */
	std::vector<unsigned int> sorted ;
	for (int i = 0; i < nb_pairs; i++) {
		if (*pairs[i].second == r_values[0]) {
			sorted.push_back(*pairs[i].first) ;
			break ;
		}
	}
	/* Fill sorted vector with r_values  */
	for (int i = 0; i < (int) r_values.size(); i++) {
		sorted.push_back(r_values[i]) ;
	}

	/* Fill l_values the same ordered way r_values was sorted */
	std::vector<unsigned int> l_values ;
	for (int i = 1; i < (int) r_values.size(); i++) {
		for (int j = 0; j < nb_pairs; j++) {
			if (*pairs[j].second == r_values[i]) {
				l_values.push_back(*pairs[j].first) ;
				break ;
			}
		}
	}

	/* Inserting lower (left) values from pairs into sorted vector, following indexing from Jacobsthal Sequence */
	for (int i = 0; i < (int) l_values.size(); i++) {
		int index = getLValIndex(l_values.size()) ;

		/* This `last_iterator` is composed of : beginning + Jacobsthal index + 2 for the gap between l_vals & r_vals + how many values have been inserted */
		std::vector<unsigned int>::iterator last_it = sorted.begin() + index + 2 + i ;
		sorted.insert(std::lower_bound(sorted.begin(), last_it, l_values[index]), l_values[index]) ;
	}

	/* Getting max value back with us in case of odd number of value */
	if (pmVector.size() % 2) {
		sorted.push_back(max) ;
	}

	/* Reset static values of Jacobsthal Sequence indices */
	getLValIndex(RESET) ;

	return sorted ;
}

std::deque<unsigned int> sortDeque(std::deque<unsigned int> pmDeque) {

	/* Get the number of pairs we'll create */
	int nb_pairs = (pmDeque.size() / 2) ;

	/* Isolating the greater value to the end in case of odd number of value */
	unsigned int max ;
	if (pmDeque.size() % 2) {
		max = *std::max_element(pmDeque.begin(), pmDeque.end()) ;
		std::deque<unsigned int>::iterator max_pos = getPosOf(pmDeque, max) ;
		pmDeque.erase(max_pos) ;
		pmDeque.push_back(max) ;
	}

	/* Making pairs of value */
	std::pair<unsigned int *, unsigned int *> pairs[nb_pairs] ;
	for (int i = 0; i < nb_pairs * 2; i += 2) {
		pairs[i / 2] = std::make_pair(&pmDeque[i], &pmDeque[i + 1]) ;

		/* Sorting each pairs individually */
		if (*pairs[i / 2].first > *pairs[i / 2].second)
			std::swap(*pairs[i / 2].first, *pairs[i / 2].second) ;
	}

	/* Base case of the recursion */
	if (pmDeque.size() <= 3)
		return pmDeque ;

	/* Insert greater (right) values of pairs into r_values */
	std::deque<unsigned int> r_values ;
	for (int i = 0; i < nb_pairs; i++) {
		r_values.push_back(*pairs[i].second) ;
	}

	/* Recursively sort greater (right) values of pairs */
	r_values = sortDeque(r_values) ;

	/* Fill sorted deque with first l_value */
	std::deque<unsigned int> sorted ;
	for (int i = 0; i < nb_pairs; i++) {
		if (*pairs[i].second == r_values[0]) {
			sorted.push_back(*pairs[i].first) ;
			break ;
		}
	}
	/* Fill sorted deque with r_values  */
	for (int i = 0; i < (int) r_values.size(); i++) {
		sorted.push_back(r_values[i]) ;
	}

	/* Fill l_values the same ordered way r_values was sorted */
	std::deque<unsigned int> l_values ;
	for (int i = 1; i < (int) r_values.size(); i++) {
		for (int j = 0; j < nb_pairs; j++) {
			if (*pairs[j].second == r_values[i]) {
				l_values.push_back(*pairs[j].first) ;
				break ;
			}
		}
	}

	/* Inserting lower (left) values from pairs into sorted deque, following indexing from Jacobsthal Sequence */
	for (int i = 0; i < (int) l_values.size(); i++) {
		int index = getLValIndex(l_values.size()) ;

		/* This `last_iterator` is composed of : beginning + Jacobsthal index + 2 for the gap between l_vals & r_vals + how many values have been inserted */
		std::deque<unsigned int>::iterator last_it = sorted.begin() + index + 2 + i ;
		sorted.insert(std::lower_bound(sorted.begin(), last_it, l_values[index]), l_values[index]) ;
	}

	/* Getting max value back with us in case of odd number of value */
	if (pmDeque.size() % 2) {
		sorted.push_back(max) ;
	}

	/* Reset static values of Jacobsthal Sequence indices */
	getLValIndex(RESET) ;
	return sorted ;
}

// Recursive function to get a Jacobsthal Sequence value
int JacobsthalSequence(int n) {
	if (n == 0)
		return 0 ;
	if (n == 1)
		return 1 ;
	return (JacobsthalSequence(n - 1) + (2 * JacobsthalSequence(n - 2))) ;
}

// Function that return a different index in each call
// Those indices are sequenced in order to optimise the sorting algorithm
int getLValIndex(int size) {
	static int jacobsthal_n = 1 ;
	static int last_group_max_index = -1 ;
	static int index = (JacobsthalSequence(jacobsthal_n) * 2) ;

	if (size == RESET) {
		jacobsthal_n = 1 ;
		last_group_max_index = -1 ;
		index = (JacobsthalSequence(jacobsthal_n) * 2) ;
		return -1 ;
	}
	
	index-- ;
	if (index == last_group_max_index) {
		last_group_max_index += (JacobsthalSequence(jacobsthal_n) * 2) ;
		jacobsthal_n++ ;
		index = (JacobsthalSequence(jacobsthal_n) * 2) + last_group_max_index ;
	}
	if (index >= size)
		index = size - 1 ;
	return index ;
}
