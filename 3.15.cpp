#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> v;
	std::string s;

	while (std::cin >> s)
	{
		v.push_back(s);
	}

	for (auto x : v)
	{
		std::cout << x << '\t';
	}

	return 0;
}