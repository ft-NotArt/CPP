#pragma once

#include <stack>
#include <deque>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack &cpy) { this->c = cpy.c ; }
	~MutantStack() {}

	MutantStack &operator=(const MutantStack &cpy) {
		this->c = cpy.c ;
		return *this ;
	}

	typedef typename std::stack<T>::container_type::iterator				iterator ;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator ;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator ;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator ;

	iterator 				begin()		{ return this->c.begin() ; }
	iterator 				end()		{ return this->c.end() ; }
	reverse_iterator 		rbegin()	{ return this->c.rbegin() ; }
	reverse_iterator 		rend()		{ return this->c.rend() ; }
	const_iterator 			cbegin()	{ return this->c.cbegin() ; }
	const_iterator 			cend()		{ return this->c.cend() ; }
	const_reverse_iterator	crbegin()	{ return this->c.crbegin() ; }
	const_reverse_iterator	crend()		{ return this->c.crend() ; }
};
