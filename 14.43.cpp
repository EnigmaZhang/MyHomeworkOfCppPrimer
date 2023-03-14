#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <functional>

int main()
{
	std::vector<int> v{ 2,3,4,5,6 };

	auto b{ std::ranges::find_if(v, 
		std::bind(std::equal_to<int>(), std::bind(std::modulus(), 5, std::placeholders::_1), 0)) };
	std::cout << (b == v.end()) << std::endl;

	b = std::ranges::find_if(v,
	std::bind(std::equal_to<int>(), std::bind(std::modulus(), 7, std::placeholders::_1), 0));
	std::cout << (b == v.end()) << std::endl;

	return 0;
}