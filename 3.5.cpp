#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::string all;
	std::string all_space;
	
	while (std::cin >> s)
	{
		all.append(s);
		if (!all_space.empty()) 
		{
			all_space.append(" ");
		}
		all_space.append(s);
	}

	std::cout << all << std::endl;
	std::cout << all_space << std::endl;

	return 0;
}