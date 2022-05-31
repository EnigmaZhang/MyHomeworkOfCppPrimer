#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

struct PersionInfo
{
	std::string name;
	std::vector<std::string> phones;
};

int main()
{
	std::string line, word;
	std::vector<PersionInfo> people;
	std::ifstream ifs{ "./8.13.txt" };
	std::istringstream record;

	while (std::getline(ifs, line))
	{
		PersionInfo info;
		record.str(line);
		record >> info.name;
		while (record >> word)
		{
			info.phones.push_back(word);
		}
		people.push_back(info);
		record.clear();
	}

	for (auto p : people)
	{
		std::cout << p.name << '\t';
		for (auto phone : p.phones)
		{
			std::cout << phone << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}