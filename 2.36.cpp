#include <iostream>
#include <typeinfo>

std::string boolToString(const bool i);

int main()
{
	int a{ 3 }, b{ 4 };
	decltype(a) c{ a };
	decltype((b))d{ a };
	++c;
	++d;

	std::cout << boolToString(typeid(c) == typeid(int)) << std::endl;
	std::cout << boolToString(typeid(d) == typeid(int)) << std::endl;
	std::cout << boolToString(a == 4) << std::endl;
	std::cout << boolToString(b == 4) << std::endl;
	std::cout << boolToString(c == 4) << std::endl;
	std::cout << boolToString(d == 4) << std::endl;


	return 0;
}

std::string boolToString(const bool i)
{
	return i ? "true" : "false";
}