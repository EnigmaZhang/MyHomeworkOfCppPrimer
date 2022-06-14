#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
	std::multimap<std::string, std::vector<std::string>> m{
		{"John",{"Banana", "Apple", "Orange"}},
		{"John", {"Hello"}},
		{"Zhang", {"Wang"}} };

	for (const auto& p : m)
	{
		std::vector<std::string> v;
		std::copy(p.second.cbegin(), p.second.cend(), std::back_inserter(v));
		std::sort(v.begin(), v.end());
		std::cout << p.first << " : ";
		std::for_each(v.cbegin(), v.cend(), [](std::string s) { std::cout << s << " "; });
		std::cout << std::endl;
	}

	return 0;
}