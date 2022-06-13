#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
	std::map<std::string, std::vector<std::string>> m;
	m["Zhang"];
	m["Wang"];
	m["Li"];

	m["Obama"].push_back("Edward");
	m["Zhang"].push_back("Enigma");

	for (const auto& w : m)
	{
		std::cout << w.first << " : ";
		std::for_each(w.second.cbegin(), w.second.cend(),
			[](const std::string& s) { std::cout << s << " "; });
		std::cout << std::endl;
	}

	return 0;
}