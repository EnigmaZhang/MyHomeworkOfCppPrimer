#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool hasFiveCharOrMore(const std::string& s);

int main()
{
	std::vector<std::string> words{ "12345", "aaabbcc", "avc", "" };

	auto false_start{ std::partition(words.begin(), words.end(), hasFiveCharOrMore) };
	for (auto iter{ words.cbegin() }; iter != false_start; ++iter)
	{
		std::cout << *iter << std::endl;
	}

	return 0;
}

bool hasFiveCharOrMore(const std::string& s)
{
	return s.length() >= 5;
}

