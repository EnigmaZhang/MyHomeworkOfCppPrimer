#include <iostream>
#include <string>

std::string(&getStringArrayRef(std::string(&a)[10]))[10];

int main()
{
	std::string a[10]{ "Hello", "World" };

	for (auto s : getStringArrayRef(a))
	{
		std::cout << s << std::endl;
	}

	return 0;
}

std::string(&getStringArrayRef(std::string(&a)[10]))[10]
{
	return a;
}
