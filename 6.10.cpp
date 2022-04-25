#include <iostream>

void swap(int* a, int* b);

int main()
{
	int a{ 1 }, b{ 2 };

	std::cout << "Before: " << a << '\t' << b << std::endl;

	swap(&a, &b);

	std::cout << "After: " << a << '\t' << b << std::endl;

	return 0;
}

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}