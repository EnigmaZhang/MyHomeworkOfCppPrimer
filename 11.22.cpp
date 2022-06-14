#include <iostream>
#include <string>
#include <vector>
#include <map>

int main()
{
	std::map<std::string, std::vector<int>> m;
	std::pair<std::map<std::string, std::vector<int>>::iterator, bool> ret{ m.insert({ "Hello", {1,2,3} }) };
	std::cout << ret.second << std::endl;

	return 0;
}