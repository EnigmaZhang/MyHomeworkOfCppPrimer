#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> v{ "a", "Hello" };

	std::cout << "Size: " << v.size() << std::endl;
	for (auto iter{ v.cbegin() }; iter != v.cend(); iter++)
	{
		std::cout << *iter << std::endl;
	}

	return 0;
}