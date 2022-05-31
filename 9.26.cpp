#include <iostream>
#include <vector>
#include <list>

int main()
{
	int ia[]{ 0,1,1,2,3,5,7,13,21,55,89 };

	std::vector<int> v(ia, ia + sizeof(ia) / sizeof(int));
	std::list<int> ls(ia, ia + sizeof(ia) / sizeof(int));

	for (auto iter{ v.cbegin() }; iter != v.cend(); )
	{
		if (*iter % 2 == 0)
		{
			iter = v.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	
	for (auto iter{ ls.cbegin() }; iter != ls.cend(); )
	{
		if (*iter % 2 == 1)
		{
			iter = ls.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	for (auto i : v)
	{
		std::cout << i << std::endl;
	}
	std::cout << std::endl;
	for (auto i : ls)
	{
		std::cout << i << std::endl;
	}
	return 0;
}