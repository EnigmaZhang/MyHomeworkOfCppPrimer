#include <iostream>
#include <algorithm>
#include <vector>

void elimDups(std::vector<int> v);

int main()
{
	std::vector<int>v{ 1, 2, 3, 4, 1, 2 };

	elimDups(v);

	return 0;
}

void elimDups(std::vector<int> v)
{
	for (auto i : v)
	{
		std::cout << i << '\t';
	}
	std::cout << std::endl;

	std::sort(v.begin(), v.end());

	for (auto i : v)
	{
		std::cout << i << '\t';
	}
	std::cout << std::endl;

	auto end_unique = std::unique(v.begin(), v.end());

	for (auto i : v)
	{
		std::cout << i << '\t';
	}
	std::cout << std::endl;

	v.erase(end_unique, v.end());
	for (auto i : v)
	{
		std::cout << i << '\t';
	}
	std::cout << std::endl;
}
