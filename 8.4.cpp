#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> v;

	auto ifs = std::ifstream("./8.2.txt");
	if (ifs)
	{
		std::string s;
		while (std::getline(ifs, s))
		{
			v.push_back(s);
		}
	}
	else
	{
		throw new std::runtime_error("File not open");
	}

	for (auto s : v)
	{
		std::cout << s << std::endl;
	}

	return 0;
}