#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int>v{ 1, 2, 3, 4 };

	std::fill_n(v.begin(), v.size(), 0);
	for (auto i : v)
	{
		std::cout << i << std::endl;
	}

	return 0;
}
