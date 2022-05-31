#include <iostream>
#include <vector>

bool f(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int n);

int main()
{
	std::vector<int> v{ 1,2,3,4,5 };
	std::cout << f(v.cbegin(), v.cend(), 4) << std::endl;
	std::cout << f(v.cbegin(), v.cend(), 6) << std::endl;
	
	return 0;
}

bool f(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int n)
{
	while (begin != end)
	{
		if (*begin == n)
		{
			return true;
		}
		++begin;
	}
	return false;
}