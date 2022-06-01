#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<char>v{ 'a', 'b', 'c' };
	std::string s{ v.begin(), v.end() };

	std::cout << s << std::endl;
	
	return 0;
}