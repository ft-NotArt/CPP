#pragma once

#include <algorithm>

template <typename T>

bool easyfind(T &cont, int n) {
	return (std::find(cont.begin(), cont.end(), n) == cont.end() ? false : true) ;
}
