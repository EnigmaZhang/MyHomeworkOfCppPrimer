#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <functional>

int main()
{
	std::vector<int> v1{ 11, 22, 9999, 1024, 1025 };
	std::vector<std::string> v2{ "pooh", "pooh", "aaa", "bbb" };
	std::vector<int> v3{ 1,0,-1,5 };

	auto count{ std::ranges::count_if(v1, std::bind(std::greater<int>(), std::placeholders::_1, 1024)) };
	std::cout << count << std::endl;

	auto f{ std::ranges::find_if_not(v2, std::bind(std::equal_to<std::string>(), std::placeholders::_1, "pooh")) };
	if (f != v2.end()) 
	{
		std::cout << *f << std::endl;
	}
	else
	{
		std::cout << "not found" << std::endl;
	}

	auto r{ std::ranges::transform(v3.begin(), v3.end(), v3.begin(), std::bind(std::multiplies<int>(), std::placeholders::_1, 2))};
	std::ranges::for_each(v3, [](auto x) {std::cout << x << std::endl; });

	return 0;
}