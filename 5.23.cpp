#include <iostream>
#include <stdexcept>

int main()
{
	int a, b;

	std::cin >> a >> b;

	std::cout << a / static_cast<double>(b) << std::endl;
	
	return 0;
}