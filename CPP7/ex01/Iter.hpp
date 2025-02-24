#pragma once

/**
 * @param len is important, calling this template with a len not corresponding to the actual array length could cause Segfaults ;
 */
template <class T> void iter(T *array, int len, void f(T &elem)) {
	for (int i = 0; i < len; i++) {
		f(array[i]) ;
	}
}

/**
 * @param len is important, calling this template with a len not corresponding to the actual array length could cause Segfaults ;
 */
template <class T> void iter(const T *array, int len, void f(const T &elem)) {
	for (int i = 0; i < len; i++) {
		f(array[i]) ;
	}
}