#include <iostream>

int main()
{	
	int a;

	std::cin >> a;

	if (a % 2 == 0)
	{
		std::cout << a << " is even";
	}
	else
	{
		std::cout << a << " is odd";
	}

	return 0;
}
