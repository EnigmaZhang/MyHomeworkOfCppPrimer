#include <iostream>
#include <string>

int compareString(const std::string& s1, const std::string& s2);
int compareCharArray(const char* s1, const char* s2);

int main()
{
	std::string s1{ "bba" }, s2{ "bbb" };
	std::cout << compareString(s1, s2) << std::endl;

	char a[]{ "bba" };
	char b[]{ "aaa" };

	std::cout << compareCharArray(a, b) << std::endl;

	return 0;
}

int compareString(const std::string& s1, const std::string& s2)
{
	if (s1.size() == s2.size())
	{
		for (auto x{ s1.cbegin() }, y{ s2.cbegin() }; x != s1.cend() && y != s2.cend(); x++, y++)
		{
			if (*x > *y)
			{
				return 1;
			}
			else if (*x < *y)
			{
				return -1;
			}
		}
		return 0;
	}
	else
	{
		return s1.size() > s2.size() ? 1 : -1;
	}
}

int compareCharArray(const char* s1, const char* s2)
{
	int toReturn{ 0 };

	auto x{ s1 }, y{ s2 };

	for (; *x != '\0' && *y != '\0'; x++, y++)
	{
		if (*x < *y)
		{
			toReturn = -1;
		}
		else if (*x > *y)
		{
			toReturn = 1;
		}
	}

	if (*x != '\0')
	{
		return 1;
	}

	if (*y != '\0')
	{
		return -1;
	}

	return toReturn;
}
