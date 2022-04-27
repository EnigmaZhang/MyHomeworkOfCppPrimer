#include <iostream>
#include <initializer_list>

int sum(std::initializer_list<int> intList);

int main()
{
	std::cout << sum({ 1,2,3 }) << std::endl;
	std::cout << sum({}) << std::endl;

	return 0;
}

int sum(std::initializer_list<int> intList)
{
	int ret{ 0 };
	for (auto i : intList)
	{
		ret += i;
	}
	return ret;
}
