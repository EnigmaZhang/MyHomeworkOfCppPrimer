#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void elimDups(std::vector<std::string>& v);

bool isShorter(const std::string& s1, const std::string& s2);

int main()
{
	std::vector<std::string>v{ "Hello", "look", "at", "me", "as", "your", "freind", "as", "me"};

	elimDups(v);
	std::stable_sort(v.begin(), v.end(), isShorter);
	for (const auto& s : v)
	{
		std::cout << s << std::endl;
	}

	return 0;
}

void elimDups(std::vector<std::string>& v)
{
	std::sort(v.begin(), v.end());

	auto end_unique = std::unique(v.begin(), v.end());

	v.erase(end_unique, v.end());
}

bool isShorter(const std::string& s1, const std::string& s2)
{
	return s1.size() < s2.size();
}
