#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int> l{ 1,2,3,4 };
	std::vector<double> v1{ l.cbegin(), l.cend() };

	for (auto d : v1)
	{
		std::cout << d << std::endl;
	}

	std::vector<int> v2{ 1,2,3,4 };
	std::vector<int> v3{ v2 };
	for (auto i : v3)
	{
		std::cout << i << std::endl;
	}
	
	return 0;
}