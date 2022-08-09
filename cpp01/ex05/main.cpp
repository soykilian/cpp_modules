#include "Karen.hpp"

int main(void)
{
	Karen karen = Karen();
	karen.complain("info");
	karen.complain("warning");
	karen.complain("error");
	karen.complain("error");
	karen.complain("debug");
	karen.complain("info");
	return(0);
}
