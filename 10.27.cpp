#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

int main()
{
	std::vector<int> v{ 1,2,3,1,1 };
	std::list<int> ls;

	std::sort(v.begin(), v.end());
	std::unique_copy(v.cbegin(), v.cend(), std::inserter(ls, ls.begin()));
	std::for_each(ls.cbegin(), ls.cend(), [](int n) {std::cout << n << std::endl; });

	return 0;
}