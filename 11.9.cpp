#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <algorithm>

int main()
{
	std::string line;
	size_t line_count{ 1 };

	std::map<std::string, std::list<size_t>> m;

	while (std::getline(std::cin, line))
	{
		std::istringstream iss{ line };
		std::string word;
		while (iss >> word)
		{
			m[word].push_back(line_count);
		}
		++line_count;
	}

	for (const auto& p : m)
	{
		std::cout << p.first << " : ";
		std::for_each(p.second.cbegin(), p.second.cend(),
			[](size_t n) { std::cout << n << " "; });
		std::cout << std::endl;
	}
	
	return 0;
}