#include <iostream>
#include <typeinfo>

std::string boolToString(const bool i);

int main()
{
	std::string s = "Who goes with Fergus?\n";

	std::cout << boolToString(s == std::string("Who goes with F\145rgus?\012")) << std::endl;
	std::cout << boolToString(std::string(typeid("Who goes with F\145rgus?\012").name()) == std::string("char const [23]")) << std::endl;

	std::cout << boolToString(std::string(typeid(3.14e1L).name()) == std::string("long double")) << std::endl;
	std::cout << boolToString(std::string(typeid(1024.f).name()) == std::string("float")) << std::endl;
	std::cout << boolToString(std::string(typeid(3.14L).name()) == std::string("long double")) << std::endl;

	return 0;
}

std::string boolToString(const bool i)
{
	return i ? "true" : "false";
}