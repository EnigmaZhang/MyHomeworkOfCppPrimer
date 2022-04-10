#include <iostream>
#include <vector>

int main()
{
	int ia[]{ 1,2,3 };

	auto begin{ std::begin(ia) };
	auto end{ std::end(ia) };
	
	for (auto p{ begin }; p < end; p++)
	{
		*p = 0;
	}

	for (auto p{ begin }; p < end; p++)
	{
		std::cout << *p << std::endl;
	}

	return 0;
}