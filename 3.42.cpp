#include <iostream>
#include <vector>

int main()
{
	int a[5];
	std::vector<int> x{ 1,2,3,4,5 };

	int* p = a;
	for (auto i : x)
	{
		*p = i;
		p++;
	}

	for (auto i : a)
	{
		std::cout << i << std::endl;
	}

	return 0;
}
