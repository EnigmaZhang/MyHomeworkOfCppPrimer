#include <iostream>

int main()
{
	int a, b;

	std::cout << "Please input two integers: " << std::endl;

	std::cin >> a >> b;

	if (a <= b)
	{
		std::cout << "Numbers between "
			<< a << " and " << b << " are: " << std::endl;
		int n{ a + 1 };
		while (n < b)
		{
			std::cout << n << "\t";
			n++;
		}

		std::cout << std::endl;
	}
	else
	{
		std::cout << a << " is larger than " << b << std::endl;
	}

	return 0;
}