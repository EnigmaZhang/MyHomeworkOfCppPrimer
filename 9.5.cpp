#include <iostream>
#include <vector>

std::vector<int>::const_iterator f(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int n);

int main()
{
	std::vector<int> v{ 1,2,3,4,5 };
	std::cout << (f(v.cbegin(), v.cend(), 4) == v.cend()) << std::endl;
	std::cout << (f(v.cbegin(), v.cend(), 6) == v.cend()) << std::endl;
	
	return 0;
}

std::vector<int>::const_iterator f(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int n)
{
	while (begin != end)
	{
		if (*begin == n)
		{
			return begin;
		}
		++begin;
	}
	return begin;
}