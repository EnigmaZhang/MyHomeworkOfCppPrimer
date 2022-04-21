#include <iostream>
#include <vector>
#include <string>

int main()
{
	int aCount{ 0 }, eCount{ 0 }, iCount{ 0 }, oCount{ 0 }, uCount{ 0 };

	char c;

	while (std::cin >> c)
	{
		if (c == 'a')
		{
			++aCount;
		}
		else if (c == 'e')
		{
			++eCount;
		}
		else if (c == 'i')
		{
			++iCount;
		}
		else if (c == 'o')
		{
			++oCount;
		}
		else if (c == 'u')
		{
			++uCount;
		}

	}

	std::cout << aCount << '\t' << eCount << '\t' << iCount << '\t' << oCount << '\t' << uCount << std::endl;


	return 0;
}
