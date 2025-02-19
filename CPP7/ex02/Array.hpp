#pragma once

#include <stdexcept>

template <typename T> class Array {
private:
	T *array ;
	int len ;
public:
	Array() ;
	Array(unsigned int n) ;
	Array(const Array &cpy) ;
	~Array();

	Array &operator=(const Array &cpy) ;

	T &operator[](int idx) ;

	int size() ;
};

template<class T> Array<T>::Array() : array(new T[0]), len(0) {}

template<class T> Array<T>::Array(unsigned int n) : array(new T[n]), len(n) {}

template<class T> Array<T>::Array(const Array<T> &cpy) : array(new T[cpy.len]), len(cpy.len) {
	for (int i = 0; i < cpy.len; i++) {
		this->array[i] = cpy.array[i] ;
	}
}

template<class T> Array<T>::~Array() { delete[] this->array ; }


template<class T> Array<T> &Array<T>::operator=(const Array<T> &cpy) {
	delete this->array ;
	this->array = new T[cpy.len] ;
	for (int i = 0; i < cpy.len; i++) {
		this->array[i] = cpy.array[i] ;
	}
	this->len = cpy.len ;
}


template<class T> T &Array<T>::operator[](int idx) {
	if (idx < 0 || idx >= this->len)
		throw std::out_of_range("Given index is out of array range") ;
	return this->array[idx] ;
}

template<class T> int Array<T>::size() { return this->len ; }
