#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>

template <typename T>
class Array{
	public:
		Array();
		Array(const Array &obj);
		~Array();
		Array(unsigned int n);
		size_t getSize(void)const;
		T* getArray(void)const;
		T &operator=(const Array &obj);
		T &operator[](int i);
		class IndexException: public std::exception{
			public:
				virtual const char* what() const throw()
				{
					return ("Invalid index");
				}
		};

	private:
		size_t size;
		T	*array;
};

template <typename T>
Array<T>::Array(void){
	this->size = 0;
	this->array = new T[0];
	std::cout << "Empty array created"<< std::endl;
}

template <typename T>
Array<T>::Array(const Array &obj)
{
	this->size = obj.getSize();
	for (size_t i = 0; i < this->size; i++)
		obj.array[i] = this->array[i];
	std::cout << "Copy constructor called"<< std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n){
	this->size = static_cast<size_t>(n);
	this->array = new T[n];
	for (size_t i = 0; i < this->size; i++)
		this->array[i] = 0;
}

template <typename T>
Array<T>::~Array(){
	std::cout << "Array has been deleted"<< std::endl;
	delete [] array;
}

template <typename T>
size_t Array<T>::getSize(void)const{
	return this->size;
}

template <typename T>
T* Array<T>::getArray(void)const{
	return this->array;
}

template <typename T>
T &Array<T>::operator=(const Array &obj){
	if (this != &obj)
	{
		delete [] this->array;
		this->size = obj.size;
		array = new T[size];
		for (size_t i = 0; i < size; i++)
			array[i] = obj.array[i];
		std::cout << "Created an array with " << size << "elements with the assingator op"<< std::endl;
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](int i){
	if (i >= static_cast<int>(this->size))
		throw Array<T>::IndexException();
	return (this->array[i]);
}

#endif
