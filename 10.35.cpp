#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v{ 1,2,3,4 };
	
	for (auto iter{ v.cend() }; iter != v.cbegin(); --iter)
	{
		std::cout << *(iter - 1) << std::endl;
	}

	return 0;
}