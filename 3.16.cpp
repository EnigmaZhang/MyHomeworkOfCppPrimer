#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> v{ "a", "Hello" };

	std::cout << "Size: " << v.size() << std::endl;
	for (auto s : v)
	{
		std::cout << s << std::endl;
	}

	return 0;
}