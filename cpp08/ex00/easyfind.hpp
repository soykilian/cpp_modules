#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
class NotFoundValue: public std::exception{

	public:
		virtual const char* what() const throw()
		{
			return ("Element was not found within the cointainer");
		}
};

template<typename T>
int easyfind(const T obj, int n){
	typename T::const_iterator elem;

	for(elem = obj.begin(); elem != obj.end(); elem++){
		if (*elem == n)
			return (n);
	}
	throw NotFoundValue();	
}

#endif
