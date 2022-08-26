#include "whatever.hpp"
#include <iostream>

int main(void)
{
	int a = 2;
	int b = 8;
	float c = 2.5f;
	float d = 2;

	std::cout << "int a = " << a << std::endl;
	std::cout << "int b = " << b << std::endl;
	std:: cout << "MAX between " << a << " & " << b << " is " << ::max(a, b) << std::endl;
	std:: cout << "MIN between " << a << " & " << b << " is " << ::min(a, b) << std::endl;
	::swap(a, b);
	std::cout  << "AFTER SWAP" << std::endl;
	std::cout << "int a = " << a << std::endl;
	std::cout << "int b = " << b << std::endl;
	std::cout  << "---------------------------------------------" << std::endl;

	std::cout << "float c = " << c << std::endl;
	std::cout << "float d = " << d << std::endl;
	std:: cout << "MAX between " << c << " & " << d << " is " << ::max(c, d) << std::endl;
	std:: cout << "MIN between " << c << " & " << d << " is " << ::min(c, d) << std::endl;
	char char_a = 'a';
	char char_b = 'b';
	std::cout  << "---------------------------------------------" << std::endl;
	std::cout << "char a = " << char_a << std::endl;
	std::cout << "char d = " << char_b << std::endl;
	std:: cout << "MAX between " << char_a << " & " << char_b << " is " << ::max(char_a, char_b) << std::endl;
	::swap(char_a, char_b);
	std::cout  << "AFTER SWAP" << std::endl;
	std::cout << "char a = " << char_a << std::endl;
	std::cout << "char b = " << char_b << std::endl;
	std::cout  << "---------------------------------------------" << std::endl;

}

