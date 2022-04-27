#include <iostream>

int getLarger(const int* a, const int b);

int main()
{
	int a{ 10 };

	std::cout << getLarger(&a, 99) << std::endl;

	return 0;
}

int getLarger(const int* a, const int b)
{
	return *a > b ? *a : b;
}