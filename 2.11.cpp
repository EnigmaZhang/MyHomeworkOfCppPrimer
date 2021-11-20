#include <iostream>

// both
extern int ix = 1024;

// both
int iy;

// declare
extern int iz;

int main()
{
	std::cout << ix << std::endl;
	std::cout << iy << std::endl;
	// std::cout << iz << std::endl;

	return 0;
}
