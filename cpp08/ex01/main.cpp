#include "span.hpp"

int main(void)
{
	Span l1 = Span(5);
	try{
		std::cout << "--------------- 5 length vector --------------"<< std::endl;
		l1.addNumber(1);
		l1.addNumber(12);
		l1.addNumber(4);
		l1.addNumber(7);
		l1.addNumber(5);
		std::cout << "Shortest span is : " << l1.shortestSpan() << std::endl;
		std::cout << "Largest span is : " << l1.longestSpan() << std::endl;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	Span l2 = Span(1);
	try{
		std::cout << "--------------- 1 length vector --------------"<< std::endl;
		l2.addNumber(1);
		std::cout << "Shortest span is : " << l2.shortestSpan() << std::endl;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	Span l3 = Span(0);
	try{
		std::cout << "----------------- Empty vector ---------------"<< std::endl;
		l2.addNumber(1);
		std::cout << "Largest span is : " << l3.longestSpan() << std::endl;
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{ std::cout << "------------- 10000 length vector ------------"<< std::endl;
		l1.addNumber(1);
		Span l4 = Span(100000);
		for( int i = 0; i < 100000 ; i++ )
		{
			l4.addNumber(i);
		}
		std::cout << "shortestSpan: " << l4.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << l4.longestSpan() << std::endl;
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}
