#include <iostream>
#include <string>
#include <cctype>

bool constainsCapital(const std::string& s);
void toLowerCase(std::string& s);

int main()
{
	std::cout << constainsCapital("Hello") << std::endl;
	std::cout << constainsCapital("") << std::endl;
	std::cout << constainsCapital("hello") << std::endl;

	std::string s{ "Hello" };
	toLowerCase(s);
	std::cout << s << std::endl;

	return 0;
}

bool constainsCapital(const std::string& s)
{
	for (auto c : s)
	{
		if (isupper(c))
		{
			return true;
		}
	}

	return false;
}

void toLowerCase(std::string& s)
{
	for (auto& c : s)
	{
		c = static_cast<char>(tolower(c));
	}
}