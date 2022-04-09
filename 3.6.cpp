#include <iostream>
#include <string>

int main()
{
	std::string s{ "Hello World!" };

	for (char& c : s)
	{
		c = 'X';
	}

	std::cout << s << std::endl;

	return 0;
}