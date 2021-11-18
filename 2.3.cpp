#include <iostream>
#include <limits>

int main()
{
	unsigned int u1{ 10 }, u2{ 42 };

	int i1{ 10 }, i2{ 42 };

	std::cout << ((u2 - u1 == 32) ? "right" : "wrong") << std::endl;
	// unsigned ranges (0, 2 ^ 32 - 1)
	std::cout << ((u1 - u2 == std::numeric_limits<unsigned int>::max() - 32 + 1) ? "right" : "wrong") << std::endl;

	std::cout << ((i2 - i1 == 32) ? "right" : "wrong") << std::endl;
	std::cout << ((i1 - i2 == -32) ? "right" : "wrong") << std::endl;

	std::cout << ((i1 - u1 == 0) ? "right" : "wrong") << std::endl;
	std::cout << ((u1 - i1 == 0) ? "right" : "wrong") << std::endl;

	return 0;
}