#include <iostream>

int fact();

int main()
{
	std::cout << fact() << std::endl;
	
	return 0;
}

int fact()
{
	int n;
	std::cout << "Please input an integer: " << std::endl;
	std::cin >> n;

	int ret{ 1 };
	while (n > 1)
	{
		ret *= n--;
	}

	return ret;
}