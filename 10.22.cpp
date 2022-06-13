#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

bool checkSize(const std::string& s, std::string::size_type sz);

int main()
{
	std::vector<std::string> v{ "aaa", "abcdefg", "123456" };

	std::cout << v.size() - std::count_if(v.cbegin(), v.cend(),
		std::bind(checkSize, std::placeholders::_1, 6 + 1)) << std::endl;

	return 0;
}

bool checkSize(const std::string& s, std::string::size_type sz)
{
	return s.length() >= sz;
}
