#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
	std::multimap<std::string, std::vector<std::string>> m{
		{"John",{"Apple", "Bananna"}},
		{"John", {"Hello"}},
		{"Zhang", {"Wang"}} };
	auto iter{ m.find("John") };
	if (iter != m.end())
	{
		m.erase(iter);
	}
	for (const auto& p : m)
	{
		std::cout << p.first << " : ";
		std::for_each(p.second.cbegin(), p.second.cend(), [](std::string s) { std::cout << s << " "; });
		std::cout << std::endl;
	}

	return 0;
}