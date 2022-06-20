#include <iostream>
#include <string>
#include <cstring>

char* concatenateStringLiteral(const char* s1, const char* s2);
char* concatenateString(const std::string& s1, const std::string& s2);

int main()
{
	char* p1{ concatenateStringLiteral("Hello ", "World") };
	std::cout << std::string(p1) << std::endl;
	delete[] p1;

	char* p2{ concatenateStringLiteral("Hello ", "World") };
	std::cout << std::string(p2) << std::endl;
	delete[] p2;

	return 0;
}

char* concatenateStringLiteral(const char* s1, const char* s2)
{
	auto l1{ std::strlen(s1) };
	auto l2{ std::strlen(s2) };
	char* s = new char[l1 + l2 + 1];

	for (auto i{ 0U }; i < l1; ++i)
	{
		s[i] = s1[i];
	}

	for (auto i{ 0U }; i < l2; ++i)
	{
		s[l1 + i] = s2[i];
	}

	s[l1 + l2] = '\0';
	return s;
}

char* concatenateString(const std::string& s1, const std::string& s2)
{
	auto l1{ s1.length()};
	auto l2{ s2.length()};
	char* s = new char[l1 + l2 + 1];

	for (auto i{ 0U }; i < l1; ++i)
	{
		s[i] = s1[i];
	}

	for (auto i{ 0U }; i < l2; ++i)
	{
		s[l1 + i] = s2[i];
	}

	s[l1 + l2] = '\0';
	return s;
}