#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::ifstream ifs{ "./9.49.txt" };
	std::string longest;
	while (ifs)
	{
		std::string word;
		ifs >> word;
		if (word.find_first_of("dfpg") == std::string::npos)
		{
			longest = longest.length() > word.length() ? longest : word;
		}
	}
	std::cout << longest << std::endl;

	return 0;
}
