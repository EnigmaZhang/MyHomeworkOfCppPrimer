#include <iostream>
#include <numeric>
#include <vector>

int main()
{
	std::vector<int> v{ 1,3,5 };
	std::cout << std::accumulate(v.cbegin(), v.cend(), 0) << std::endl;

	return 0;
}
