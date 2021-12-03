#include <iostream>
#include <typeinfo>

std::string boolToString(const bool i);

int main()
{
	std::cout << boolToString(typeid('a') == typeid(char)) << std::endl;
	std::cout << boolToString(typeid(L'a') == typeid(wchar_t)) << std::endl;
	std::cout << boolToString(typeid("a") == typeid(const char[2])) << std::endl;
	std::cout << boolToString(typeid(L"a") == typeid(const wchar_t[2])) << std::endl;
	std::cout << boolToString(typeid(10) == typeid(int)) << std::endl;
	std::cout << boolToString(typeid(10U) == typeid(unsigned int)) << std::endl;
	std::cout << boolToString(typeid(10L) == typeid(long)) << std::endl;
	std::cout << boolToString(typeid(10UL) == typeid(unsigned long)) << std::endl;
	std::cout << boolToString(typeid(012) == typeid(int)) << std::endl;
	std::cout << boolToString(typeid(0XC) == typeid(int)) << std::endl;
	std::cout << boolToString(typeid(3.14) == typeid(double)) << std::endl;
	std::cout << boolToString(typeid(3.14F) == typeid(float)) << std::endl;
	std::cout << boolToString(typeid(3.14L) == typeid(long double)) << std::endl;
	std::cout << boolToString(typeid(10) == typeid(int)) << std::endl;
	std::cout << boolToString(typeid(10U) == typeid(unsigned int)) << std::endl;
	std::cout << boolToString(typeid(10.) == typeid(double)) << std::endl;
	std::cout << boolToString(typeid(10E-2) == typeid(double)) << std::endl;

	return 0;
}

std::string boolToString(const bool i)
{
	return i ? "true" : "false";
}