#include <iostream>

void reset(int& n);

int main()
{
	int a{ 99 };

	std::cout << "Before: " << a << std::endl;

	reset(a);

	std::cout << "After: " << a << std::endl;

	return 0;
}

void reset(int& n)
{
	n = 0;
}