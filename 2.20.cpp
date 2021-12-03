#include <iostream>

int main()
{
	int i{ 42 };
	int* p{ &i };

	*p = *p * *p;

	// i * i
	std::cout << i << std::endl;

	return 0;
}
