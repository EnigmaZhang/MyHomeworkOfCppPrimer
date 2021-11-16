#include <iostream>

int main()
{
	int sum{ 0 };
	int n;

	while (std::cin >> n)
	{
		sum += n;
	}

	std::cout << sum << std::endl;

	return 0;
}