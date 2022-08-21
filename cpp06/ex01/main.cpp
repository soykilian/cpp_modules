#include "Data.hpp"
#include <iostream>
/*
struct Data{
	int n;
};
*/

uintptr_t serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}

int main(){
	Data *a = new Data;
	Data *b ;
	uintptr_t raw;

	raw = serialize(a);
	b = deserialize(raw);
	std::cout << "Data is : " << a << std::endl;
	std::cout << "Integer is : " << raw << std::endl;
	std::cout << "Deserialized is : " << b << std::endl;
	delete a;
	return 0;
}
