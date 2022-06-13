#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v{ 1,2,3,4 };
	std::for_each(v.crbegin(), v.crend(), [](int n) {std::cout << n << " "; });
	std::cout << std::endl;

	return 0;
}