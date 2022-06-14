#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
	std::map<std::string, std::vector<int>> m{ {"Hello", {1,2,3}} };

	std::map<std::string, std::vector<int>>::iterator iter{ m.find("Hello") };
	
	if (iter != m.end())
	{
		std::for_each(iter->second.cbegin(), iter->second.cend(), [](int n) { std::cout << n << " "; });
		std::cout << std::endl;
	}

	return 0;
}