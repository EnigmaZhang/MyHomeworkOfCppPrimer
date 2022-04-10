#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main()
{
	std::vector<std::string> v;
	std::string in;

	while (std::cin >> in)
	{
		v.push_back(in);
	}

	for (auto s : v)
	{
		for (auto& c : s)
		{
			c = static_cast<char>(toupper(c));
		}
	}

	int count{ 0 };
	for (auto s : v)
	{
		count++;
		std::cout << s << ' ';
		if (count == 8)
		{
			std::cout << std::endl;
			count = 0;
		}
	}

	return 0;
}