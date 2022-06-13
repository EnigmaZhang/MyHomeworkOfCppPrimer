#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <cctype>
#include <unordered_map>

int main()
{
	std::unordered_map<std::string, size_t> word_count;
	std::string word;

	while (std::cin >> word)
	{
		std::transform(word.cbegin(), word.cend(), word.begin(),
			[](char c) { return static_cast<char>(std::tolower(c)); });
		word.erase(std::remove_if(word.begin(), word.end(), std::ispunct), word.end());
		++word_count[word];
	}

	for (const auto& w : word_count)
	{
		std::cout << w.first << " : " << w.second << std::endl;
	}

	return 0;
}