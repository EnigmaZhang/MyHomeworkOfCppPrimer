#include <iostream>
#include <list>
#include <deque>
#include <string>

int main()
{
	std::list<int> ls{ 1,2,3,4,5,6 };
	std::deque<int> odd, even;

	for (auto i : ls)
	{
		if (i % 2 == 0)
		{
			even.push_back(i);
		}
		else
		{
			odd.push_back(i);
		}
	}

	for (auto i : odd)
	{
		std::cout << i << std::endl;
	}

	for (auto i : even)
	{
		std::cout << i << std::endl;
	}

	return 0;
}