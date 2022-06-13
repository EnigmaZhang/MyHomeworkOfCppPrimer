#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
	std::map<std::string, std::vector<std::pair<std::string, std::string>>> m;
	m["Zhang"];
	m["Wang"];
	m["Li"];

	m["Obama"].push_back({ "Edward", "20000101" });
	m["Zhang"].push_back({ "Enigma", "19990808" });

	for (const auto& w : m)
	{
		std::cout << w.first << " : ";
		std::for_each(w.second.cbegin(), w.second.cend(),
			[](std::pair<std::string, std::string> p) { std::cout << p.first << " " << p.second << " "; });
		std::cout << std::endl;
	}

	return 0;
}