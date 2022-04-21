#include <iostream>
#include <vector>
#include <string>

int main()
{
	int aCount{ 0 }, eCount{ 0 }, iCount{ 0 }, oCount{ 0 }, uCount{ 0 };
	int blankCount{ 0 };

	char c;

	while ((c = static_cast<char>(std::cin.get())) != EOF)
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
		case ' ':
		case '\t':
		case '\n':
			++blankCount;
			break;
		default:
			break;
		}

	}

	std::cout << "vowel count: " <<  aCount << '\t' << eCount << '\t' << iCount << '\t' << oCount << '\t' << uCount << std::endl;
	std::cout << "blank count: " << blankCount << std::endl;


	return 0;
}
