#include <iostream>
#include <string>

int main()
{
	std::string s{ "Hello World!" };

	std::string::size_type i{ 0 };
	while (i < s.length())
	{
		s[i] = 'X';
		i++;
	}

	std::cout << s << std::endl;

	s = "Hello World!";
	for (std::string::size_type j{ 0 }; j < s.length(); j++)
	{
		s[j] = 'X';
	}
	std::cout << s << std::endl;

	return 0;
}