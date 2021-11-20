#include <iostream>
#include <typeinfo>

std::string boolToString(const bool i);

int main()
{
	std::cout << boolToString(std::string(typeid('a').name()) == std::string("char")) << std::endl;
	std::cout << boolToString(std::string(typeid(L'a').name()) == std::string("wchar_t")) << std::endl;
	std::cout << boolToString(std::string(typeid("a").name()) == std::string("char const [2]")) << std::endl;
	std::cout << boolToString(std::string(typeid(L"a").name()) == std::string("wchar_t const [2]")) << std::endl;
	std::cout << boolToString(std::string(typeid(10).name()) == std::string("int")) << std::endl;
	std::cout << boolToString(std::string(typeid(10U).name()) == std::string("unsigned int")) << std::endl;
	std::cout << boolToString(std::string(typeid(10L).name()) == std::string("long")) << std::endl;
	std::cout << boolToString(std::string(typeid(10UL).name()) == std::string("unsigned long")) << std::endl;
	std::cout << boolToString(std::string(typeid(012).name()) == std::string("int")) << std::endl;
	std::cout << boolToString(std::string(typeid(0XC).name()) == std::string("int")) << std::endl;
	std::cout << boolToString(std::string(typeid(3.14).name()) == std::string("double")) << std::endl;
	std::cout << boolToString(std::string(typeid(3.14F).name()) == std::string("float")) << std::endl;
	std::cout << boolToString(std::string(typeid(3.14L).name()) == std::string("long double")) << std::endl;
	std::cout << boolToString(std::string(typeid(10).name()) == std::string("int")) << std::endl;
	std::cout << boolToString(std::string(typeid(10U).name()) == std::string("unsigned int")) << std::endl;
	std::cout << boolToString(std::string(typeid(10.).name()) == std::string("double")) << std::endl;
	std::cout << boolToString(std::string(typeid(10E-2).name()) == std::string("double")) << std::endl;

	return 0;
}

std::string boolToString(const bool i)
{
	return i ? "true" : "false";
}