#include <iostream>
#include <string>

int i{ 42 };

std::string boolToString(const bool i);

int main()
{
	int i{ 100 };
	int j{ i };

	std::cout << boolToString(j == 100) << std::endl;

	return 0;
}

std::string boolToString(const bool i)
{
	return i ? "true" : "false";
}
