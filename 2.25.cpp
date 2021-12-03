#include <iostream>
#include <typeinfo>

std::string boolToString(const bool i);

int main()
{
	int* p1, *& r1{ p1 };

	std::cout << boolToString(typeid(p1) == typeid(int *)) << std::endl;
	std::cout << boolToString(typeid(r1) == typeid(int *)) << std::endl;

	int i, * p2{ 0 };

	std::cout << boolToString(typeid(i) == typeid(int)) << std::endl;
	std::cout << boolToString(typeid(p2) == typeid(int *)) << std::endl;

	int* p3, * p4;

	std::cout << boolToString(typeid(p3) == typeid(int *)) << std::endl;
	std::cout << boolToString(typeid(p4) == typeid(int *)) << std::endl;

	return 0;
}

std::string boolToString(const bool i)
{
	return i ? "true" : "false";
}