#include <iostream>
#include <string>
#include <ctype.h>

int main()
{
	char c;
	c = static_cast<char>(std::cin.get());
	std::string s;

	while (c != EOF)
	{
		if (!isspace(c)) {
			s.push_back(c);
		}
		else
		{
			if (!s.empty()) {
				std::cout << "Get a word: " << s << std::endl;
			}
			s.clear();
		}
		c = static_cast<char>(std::cin.get());
	}

	return 0;
}