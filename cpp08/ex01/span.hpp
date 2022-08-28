#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <vector>
class Span{

	private: 
		unsigned int	_n;
		std::vector<int> _container;
		Span();
	public:
		~Span();
		Span(unsigned int);
		Span(const Span &obj);
		Span &operator=(const Span &obj);
		void addNumber(int a);

		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
		class TooManyElements : public std::exception{
			public:
			TooManyElements(){}
				virtual ~TooManyElements() throw() {}
				const char * what() const throw(){
					return "There is no place for another element to be added";
				};
		};
		class SpanNotEnough : public std::exception{
			public:
				const char * what() const throw(){
					return "Not enough elements to calculate span";
				};
		};

};
#endif
