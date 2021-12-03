#include <iostream>

int main()
{
	int i{ 0 };

	// int* to double*
	// double* dp{ &i };

	// int to int*
	// int* ip{ i };

	int* p{ &i };

	std::cout << *p << std::endl;

	return 0;
}
