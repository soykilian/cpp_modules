#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
template<typename T>
void iter(T *p, std::size_t len, void (*func) (const T&var)){
	for (std::size_t i = 0; i < len ; i++)
		func(p[i]);
}
#endif

