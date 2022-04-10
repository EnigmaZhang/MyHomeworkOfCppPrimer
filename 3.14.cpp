#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<int> v;
	int i;

	while (std::cin >> i)
	{
		v.push_back(i);
	}

	for (auto x : v)
	{
		std::cout << x << '\t';
	}

	return 0;
}