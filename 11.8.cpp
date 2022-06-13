#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::string word;

	std::vector<std::string> excludes{ "An", "The", "Am", "With", "An" };
	std::sort(excludes.begin(), excludes.end());
	excludes.erase(std::unique(excludes.begin(), excludes.end()), excludes.end());

	while (std::cin >> word)
	{
		if (std::find(excludes.cbegin(), excludes.cend(), word) == excludes.end())
		{
			excludes.push_back(word);
		}
	}
	std::for_each(excludes.cbegin(), excludes.cend(),
		[](const std::string& s) { std::cout << s << " "; });
	std::cout << std::endl;
	return 0;
}