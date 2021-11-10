#include <iostream>

int main()
{
	int n{ 10 };

	while (n >=0)
	{
		std::cout << n << "\t";
		n--;
	}

	std::cout << std::endl;

	return 0;
}