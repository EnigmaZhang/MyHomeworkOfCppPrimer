#include <iostream>

int main()
{
	int i{ 100 }, sum{ 0 };
	for (int i{ 0 }; i != 10; ++i)
	{
		sum += i;
	}

	// 100, 45
	std::cout << i << " " << sum << std::endl;

	return 0;
}
