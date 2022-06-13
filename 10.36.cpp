#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> ls{ 1, 2, 0, 0, 5 };
	std::cout << *(--std::find(ls.crbegin(), ls.crend(), 0)) << std::endl;

	return 0;
}