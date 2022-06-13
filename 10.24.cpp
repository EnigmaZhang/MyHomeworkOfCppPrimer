#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

bool checkSize(const std::string& s, std::string::size_type sz);

int main()
{
	std::vector<int> v{ 1, 2, 5 };
	std::string s{ "xyz" };

	std::cout << *std::find_if_not(v.cbegin(), v.cend(), 
		std::bind(checkSize, s, std::placeholders::_1)) << std::endl;

	return 0;
}

bool checkSize(const std::string& s, std::string::size_type sz)
{
	return s.length() >= sz;
}
