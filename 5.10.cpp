#include <iostream>
#include <vector>
#include <string>

int main()
{
	int aCount{ 0 }, eCount{ 0 }, iCount{ 0 }, oCount{ 0 }, uCount{ 0 };

	char c;

	while (std::cin >> c)
	{
		switch (c)
		{
		case 'a':
		case 'A':
			++aCount;
			break;
		case 'e':
		case 'E':
			++eCount;
			break;
		case 'i':
		case 'I':
			++iCount;
			break;
		case 'o':
		case 'O':
			++oCount;
			break;
		case 'u':
		case 'U':
			++uCount;
			break;
		default:
			break;
		}

	}

	std::cout << aCount << '\t' << eCount << '\t' << iCount << '\t' << oCount << '\t' << uCount << std::endl;


	return 0;
}
