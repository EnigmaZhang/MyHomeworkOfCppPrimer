#include <iostream>
#include <string>

int main()
{
	std::string last{ "" };
	std::string now;

	int count{ 0 };
	int maxDuplicate{ 0 };
	while (std::cin >> now)
	{
		if (now == last)
		{
			++count;
		}
		else
		{
			maxDuplicate = maxDuplicate > count ? maxDuplicate : count;
			count = 0;
		}
		last = now;
	}
	maxDuplicate = maxDuplicate > count ? maxDuplicate : count;
	if (maxDuplicate == 0)
	{
		std::cout << "No duplicates" << std::endl;
	}
	else
	{
		std::cout << maxDuplicate + 1 << " duplicates" << std::endl;
	}


	return 0;
}
