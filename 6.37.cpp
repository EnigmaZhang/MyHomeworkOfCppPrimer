#include <iostream>
#include <string>

std::string x[10];

typedef std::string(STRING_ARRAY)[10];

STRING_ARRAY& getStringArrayRefA(STRING_ARRAY& a);

auto getStringArrayRefB(std::string(&a)[10])->std::string(&)[10];

decltype((x)) getStringArrayRefC(std::string(&a)[10]);

int main()
{
	std::string a[10]{ "Hello", "World" };

	for (auto s : getStringArrayRefA(a))
	{
		std::cout << s << std::endl;
	}

	for (auto s : getStringArrayRefB(a))
	{
		std::cout << s << std::endl;
	}

	for (auto s : getStringArrayRefC(a))
	{
		std::cout << s << std::endl;
	}

	return 0;
}

STRING_ARRAY& getStringArrayRefA(STRING_ARRAY& a)
{
	return a;
}

auto getStringArrayRefB(std::string(&a)[10])->std::string(&)[10]
{
	return a;
}

decltype((x)) getStringArrayRefC(std::string(&a)[10])
{
	return a;
}
