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

	for (std::vector<int>::size_type j{ 0 }; j < v.size() - 1; j++)
	{
		std::cout << v[j] + v[j + 1] << '\t';
	}
	std::cout << std::endl;

	for (std::vector<int>::size_type j{ 0 }; j < (v.size() + 1) / 2; j++)
	{
		std::cout << v[j] + v[v.size() - 1 - j] << '\t';
	}
	std::cout << std::endl;

	return 0;
}