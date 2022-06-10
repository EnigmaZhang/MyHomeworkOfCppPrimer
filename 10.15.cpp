#include <iostream>

int main()
{
	int a{ 99 };
	auto lambda_sum{ [a](int n) { return a + n; } };
	std::cout << lambda_sum(1) << std::endl;

	return 0;
}

