#include <iostream>

void swap(int*& a, int*& b);

int main()
{
	int x{ 10 }, y{ 20 };
	int* a{ &x }, * b{ &y };

	swap(a, b);
	std::cout << x << '\t' << y << std::endl;
	std::cout << *a << '\t' << *b << std::endl;

	return 0;
}

void swap(int*& a, int*& b)
{
	int* tmp{ a };
	a = b;
	b = tmp;
}