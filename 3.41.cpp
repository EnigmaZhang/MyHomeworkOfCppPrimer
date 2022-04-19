#include <iostream>
#include <vector>

int main()
{
	int a[]{ 1,2,3,4,5 };
	std::vector<int> x(std::begin(a), std::end(a));

	for (auto i : x)
	{
		std::cout << i << std::endl;
	}

	return 0;
}
