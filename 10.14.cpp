#include <iostream>

int main()
{
	auto lambda_sum{ [](int a, int b) { return a + b; } };
	std::cout << lambda_sum(1, 2) << std::endl;

	return 0;
}

