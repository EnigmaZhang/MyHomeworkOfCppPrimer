#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1(10, 42);
	std::vector<int> v2{ 42,42,42,42,42,42,42,42,42,42 };
	std::vector<int> v3;
	for (int i{ 0 }; i < 10; i++)
	{
		v3.push_back(42);
	}

	std::cout << v1.size() << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << v3.size() << std::endl;

	return 0;
}