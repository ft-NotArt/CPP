#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <utility>
#include <algorithm>

#define RESET -1

// This function returns an iterator to the first occurence of value in container, this works well as we're working with no duplicates series of values
template <typename Container>
typename Container::iterator getPosOf(Container &container, unsigned int value) {
	for (typename Container::iterator it = container.begin(); it != container.end(); ++it) {
		if (*it == value) {
			return it ;
		}
	}
	return container.end() ;
} ;

class PmergeMe
{
public:
	std::vector<unsigned int> pmVector ;
	std::deque<unsigned int> pmDeque ;

	PmergeMe() ;
	PmergeMe(std::vector<unsigned int> &pmVector, std::deque<unsigned int> &pmDeque) ;
	PmergeMe(const PmergeMe &cpy) ;
	~PmergeMe() ;

	PmergeMe &operator=(const PmergeMe &cpy) ;

	void printVector() ;
} ;

std::vector<unsigned int> sortVector(std::vector<unsigned int> pmVector) ;
std::deque<unsigned int> sortDeque(std::deque<unsigned int> pmDeque) ;
int JacobsthalSequence(int n) ;
int getLValIndex(int size) ;
