#include <iostream>
#include <algorithm>
#include <list>

int main()
{
	std::list<int> v;
	int x;
	while (std::cin >> x)
	{
		v.push_back(x);
	}
	std::cout << std::count(v.cbegin(), v.cend(), 1) << std::endl;
	std::cout << std::count(v.cbegin(), v.cend(), 3) << std::endl;

	return 0;
}
