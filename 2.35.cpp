#include <iostream>
#include <typeinfo>

std::string boolToString(const bool i);

int main()
{
	const int i{ 42 };
	auto j{ i };
	const auto& k{ i };
	auto* p{ &i };
	const auto j2{ i }, & k2{ i };
	
	std::cout << boolToString(typeid(j) == typeid(int)) << std::endl;
	std::cout << boolToString(typeid(k) == typeid(const int)) << std::endl;
	std::cout << boolToString(typeid(p) == typeid(const int*)) << std::endl;
	std::cout << boolToString(typeid(j2) == typeid(const int)) << std::endl;
	std::cout << boolToString(typeid(k2) == typeid(const int)) << std::endl;

	return 0;
}

std::string boolToString(const bool i)
{
	return i ? "true" : "false";
}