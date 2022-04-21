#include <iostream>

int main()
{
	int i;
	double d;

	std::cin >> i >> d;

	std::cout << (i *= static_cast<int>(d)) << std::endl;

	return 0;
}
