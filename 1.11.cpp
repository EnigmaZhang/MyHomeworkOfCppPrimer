#include <iostream>

int main()
{
	int a, b;

	std::cout << "Please input two integers: " << std::endl;

	std::cin >> a >> b;

	int smaller{ a < b ? a : b };
	int larger{ a > b ? a : b };

	int n{ smaller + 1 };

	std::cout << "Numbers between "
		<< smaller << " and " << larger << " are: " << std::endl;
	while (n < larger)
	{
		std::cout << n << "\t";
		n++;
	}

	std::cout << std::endl;

	return 0;
}