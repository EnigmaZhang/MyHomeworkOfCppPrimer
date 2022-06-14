#include <iostream>
#include <string>
#include <map>

int main()
{
	std::map<std::string, size_t> word_count;
	std::string word;

	while (std::cin >> word)
	{
		auto ret{ word_count.insert({word, 1}) };
		if (!ret.second)
		{
			++ret.first->second;
		}
	}

	for (const auto& w : word_count)
	{
		std::cout << w.first << " : " << w.second << std::endl;
	}

	return 0;
}