#include "RPN.hpp"

int main(int argc, char *argv[]){
	if (argc != 2 || argv[1]== '\0' || std::string(argv[1]).size() == 0)
		return (1);
	RPN obj(argv[1]);
	return (0);
}
