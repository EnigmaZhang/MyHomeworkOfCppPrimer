#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

int main()
{
	std::unordered_map<std::string, size_t> word_count;
	std::string word;

	while (std::cin >> word)
	{
		++word_count[word];
	}

	for (const auto& w : word_count)
	{
		std::cout << w.first << " : " << w.second << std::endl;
	}

	return 0;
}