#include <iostream>
#include "Chapter6.h"

int main()
{
	std::cout << fact(5) << std::endl;
	std::cout << fact() << std::endl;
	std::cout << abs(0) << '\t' << abs(99) << '\t' << abs(-10) << std::endl;

	return 0;
}

int fact(int n)
{
	int ret{ 1 };
	while (n > 1)
	{
		ret *= n--;
	}

	return ret;
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

int myAbs(int n)
{
	return n < 0 ? -n : n;
}