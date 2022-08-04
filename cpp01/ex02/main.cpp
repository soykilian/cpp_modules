#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string &stringREF = str;
	std::string *stringPTR = &str;
	std::cout << "\""+ str + "\" THIS IS A STRING\n" << &stringREF << " THIS IS THE REF ADDRESS " 
		<< "\"" << stringREF << "\"" << " THIS IS THE REF VALUE\n" << stringPTR << " THIS IS THE PTR ADDR "<<"\"" << *stringPTR << "\"" << " THIS IS THE PTR VALUE" << std::endl;
}
