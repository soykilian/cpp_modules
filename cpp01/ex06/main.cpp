#include "Karen.hpp"

int main(int argc, char*argv[])
{
	Karen karen = Karen();
	if (argc != 2)
		return (1);
	if (std::string(argv[1]).empty())
		return (1);
	karen.complain(std::string(argv[1]));
	return(0);
}
