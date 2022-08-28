#include <iostream>
#include "span.hpp"
Span::Span(){}

Span::~Span(){
	std::cout << "Span deleted"<< std::endl;
}

Span::Span(unsigned int n){
	this->_n = n;
}

Span::Span(const Span &obj){
	this->_n = obj._n;
	this->_container.clear();
	this->_container = obj._container;
}

Span &Span::operator=(const Span &obj){
	if(this != &obj)
	{
		this->_n = obj._n;
		this->_container.clear();
		this->_container = obj._container;
	}
	return (*this);
}

void Span::addNumber(int a){
	if (this->_container.size() >= this->_n)
		throw TooManyElements();
	this->_container.push_back(a);
}

unsigned int Span::shortestSpan(void){
	unsigned int diff;

	diff = 0;
	if (this->_container.size() <= 1)
		throw SpanNotEnough();
	std::vector<int>::iterator start = this->_container.begin();
	std::vector<int>::iterator second = ++this->_container.begin();
	diff = std::abs(*start - *second);
	while (second !=this->_container.end())
	{
		if (diff > static_cast<unsigned int>(std::abs(*start - *second)))
			diff = std::abs(*start - *second);
		start++;
		second++;
	}
	return diff;
}

unsigned int Span::longestSpan(void){
	if (this->_container.size() <= 1)
		throw SpanNotEnough();
	std::sort(this->_container.begin(), this->_container.end());
	return (std::abs(*(this->_container.begin()) - *(--this->_container.end())));
}
