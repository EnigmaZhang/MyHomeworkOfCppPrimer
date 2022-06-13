#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> v{ "HelloHere", "me", "Interesting", "abcdef" };
	std::cout << std::count_if(v.cbegin(), v.cend(),
		[](const std::string& s) { return s.length() > 6; }) << std::endl;

	return 0;
}
