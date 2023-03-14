#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <ranges>
#include <algorithm>

int add(int a, int b);

class Div
{
public:
	int operator()(int i, int j)
	{
		return i / j;
	}
};

int main()
{
	auto mod{ [](int i, int j) {return i % j; } };

	std::map<std::string, std::function<int(int, int)>> binops
	{
		{"+", add},
		{"-", std::minus<int>()},
		{"*", [](int i, int j) {return i * j; }},
		{"/", Div()},
		{"%", mod},
	};

	std::ranges::for_each(binops, [&](auto c) {std::cout << c.first << ":" << c.second(7, 2) << std::endl; });

	return 0;
}

int add(int a, int b)
{
	return a + b;
}