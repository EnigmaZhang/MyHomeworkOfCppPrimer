#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

int main()
{
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9 };
	std::vector<int> v1, v3;
	std::list<int> v2;

	std::copy(v.cbegin(), v.cend(), std::back_inserter(v1));
	std::copy(v.cbegin(), v.cend(), std::front_inserter(v2));
	std::copy(v.cbegin(), v.cend(), std::inserter(v3, v3.begin()));

	std::for_each(v1.cbegin(), v1.cend(), [](int n) {std::cout << n << ' '; });
	std::cout << std::endl;
	std::for_each(v2.cbegin(), v2.cend(), [](int n) {std::cout << n << ' '; });
	std::cout << std::endl;
	std::for_each(v3.cbegin(), v3.cend(), [](int n) {std::cout << n << ' '; });
	std::cout << std::endl;

	return 0;
}