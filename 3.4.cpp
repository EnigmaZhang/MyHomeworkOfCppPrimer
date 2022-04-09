#include <iostream>
#include <string>

int main()
{
	std::string a, b;

	std::cin >> a >> b;

	if (a == b) 
	{
		std::cout << "Two strings are equal" << std::endl;
	}
	else
	{
		std::cout << "String " << std::max(a, b) << " is larger" << std::endl;
	}

	if (a.length() == b.length())
	{
		std::cout << "Two strings have the same length" << std::endl;
	}
	else
	{
		std::cout << (a.length() > b.length() ? a : b) << " is longer" << std::endl;
	}

	return 0;
}