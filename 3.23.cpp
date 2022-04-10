#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<int> v{ 1,2,3,4,5,5,4,3,2,1 };

	for (auto iter{ v.begin() }; iter != v.end(); iter++)
	{
		*iter = 2 * *iter;
	}

	for (auto iter{ v.begin() }; iter != v.end(); iter++)
	{
		std::cout << *iter << '\t';
	}
	std::cout << std::endl;

	return 0;
}