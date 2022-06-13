#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::vector<std::pair<std::string, int>> v;

	while (true)
	{
		std::string s;
		int n;

		if (std::cin)
		{ 
			std::cin >> s;
		}
		else
		{
			break;
		}

		if (std::cin)
		{
			std::cin >> n;
		}
		else
		{
			break;
		}

		v.push_back(std::make_pair(s, n));
	}

	std::for_each(v.cbegin(), v.cend(),
		[](std::pair<std::string, int> p) { std::cout << p.first << " " << p.second << std::endl; });

	return 0;
}
