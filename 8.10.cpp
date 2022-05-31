#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::ifstream ifs{ "8.10.txt" };
	std::string line;
	std::vector<std::string> v;

	while (std::getline(ifs, line))
	{
		v.push_back(line);
	}

	for (auto s : v)
	{
		std::cout << s << std::endl;
	}

	for (auto v_line : v)
	{
		std::string s;
		std::istringstream iss{ v_line };
		while (iss >> s)
		{
			std::cout << s << std::endl;
		}
	}

	return 0;
}