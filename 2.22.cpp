#include <iostream>

int main()
{
	int i{ 0 };

	int* p{ &i };

	if (p)
	{
		std::cout << "p is not NULL" << std::endl;
	}
	else
	{
		std::cout << "p is NULL" << std::endl;
	}

	if (*p)
	{
		std::cout << "bool(*p) is true" << std::endl;
	}
	else
	{
		std::cout << "bool(*p) is false" << std::endl;
	}


	return 0;
}
