#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::list<int> ls;

	std::copy(v.crbegin() + 3, v.crbegin() + 8, std::back_inserter(ls));
	std::for_each(ls.cbegin(), ls.cend(), [](int n) {std::cout << n << ' '; });
	std::cout << std::endl;

	return 0;
}