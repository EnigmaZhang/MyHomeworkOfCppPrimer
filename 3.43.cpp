#include <iostream>

int main()
{	
	int ia[2][3]{ {1,2,3},{10,9,8} };

	for (int (&p)[3] : ia)
	{
		for (int i : p)
		{
			std::cout << i << '\t';
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (size_t i{ 0 }; i < sizeof(ia) / sizeof(ia[0]); i++)
	{
		for (size_t j{ 0 }; j < sizeof(ia[0]) / sizeof(int); j++)
		{
			std::cout << ia[i][j] << '\t';
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int(*p)[3]{ std::begin(ia) }; p != std::end(ia); p++)
	{
		for (int* q{ std::begin(*p) }; q != std::end(*p); q++)
		{
			std::cout << *q << '\t';
		}
		std::cout << std::endl;
	}

	return 0;
}
