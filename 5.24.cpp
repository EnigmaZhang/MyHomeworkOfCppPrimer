#include <iostream>
#include <stdexcept>

int main()
{
	int a, b;

	std::cin >> a >> b;

	if (b == 0)
	{
		throw std::runtime_error("A number divided by zero");
	}
	std::cout << a / static_cast<double>(b) << std::endl;
	
	return 0;
}