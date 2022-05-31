#include <iostream>
#include <forward_list>

int main()
{
	std::forward_list<int> fl{ 1,2,3,4,5 };

	for (auto prev{ fl.cbefore_begin() }, curr{ fl.cbegin() }; curr != fl.cend();)
	{
		if (*curr % 2 == 1)
		{
			curr = fl.erase_after(prev);
		}
		else
		{
			prev = curr;
			++curr;
		}
	}

	for (auto i : fl)
	{
		std::cout << i << std::endl;
	}
	
	return 0;
}