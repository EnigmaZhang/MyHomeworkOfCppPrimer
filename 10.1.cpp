#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> v;
	while (std::cin)
	{
		int x;
		std::cin >> x;
		v.push_back(x);
	}
	std::cout << std::count(v.cbegin(), v.cend(), 1) << std::endl;
	std::cout << std::count(v.cbegin(), v.cend(), 3) << std::endl;

	return 0;

}
