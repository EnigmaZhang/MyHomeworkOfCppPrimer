#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	int i;

	while (std::cin >> i)
	{
		v.push_back(i);
	}

	for (auto iter{ v.cbegin() }; iter != v.cend() - 1; iter++)
	{
		std::cout << *iter + *(iter + 1) << '\t';
	}
	std::cout << std::endl;

	for (auto iter{ v.cbegin() }; iter != v.cbegin() + (v.cend() - v.cbegin()) / 2 + 1; iter++)
	{
		std::cout << *iter + *(v.cbegin() + (v.cend() - iter - 1)) << '\t';
	}
	std::cout << std::endl;

	return 0;
}