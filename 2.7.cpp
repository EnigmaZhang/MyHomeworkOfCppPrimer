#include <iostream>
#include <typeinfo>

std::string boolToString(const bool i);

int main()
{
	std::string s = "Who goes with Fergus?\n";

	std::cout << boolToString(s == std::string("Who goes with F\145rgus?\012")) << std::endl;
	std::cout << boolToString(typeid("Who goes with F\145rgus?\012") == typeid(const char[23])) << std::endl;

	std::cout << boolToString(typeid(3.14e1L) == typeid(long double)) << std::endl;
	std::cout << boolToString(typeid(1024.f) == typeid(float)) << std::endl;
	std::cout << boolToString(typeid(3.14L) == typeid(long double)) << std::endl;

	return 0;
}

std::string boolToString(const bool i)
{
	return i ? "true" : "false";
}