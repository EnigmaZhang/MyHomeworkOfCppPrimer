#include <iostream>

int main()
{
	int n{ 3 };
	auto f{ [&n]() { return n == 0 ? true : --n == 0; } };
	std::cout << f() << " " << n << std::endl;
	std::cout << f() << " " << n << std::endl;
	std::cout << f() << " " << n << std::endl;
	std::cout << f() << " " << n << std::endl;

	return 0;
}
