#include <iostream>
#include <string>

bool isEmpty(const std::string& s);

int main()
{
	std::cout << isEmpty("Hello") << std::endl;
	std::cout << isEmpty("") << std::endl;

	return 0;
}

bool isEmpty(const std::string& s)
{
	return s.empty();
}