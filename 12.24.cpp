#include <iostream>
#include <string>
#include <cctype>

int main()
{
	size_t init_size{ 8U };
	size_t length{ 0U };

	char* p = new char[init_size];
	char c;
	while (std::cin.get(c))
	{
		if (length == init_size)
		{
			init_size *= 2;
			char* tmp = new char[init_size];
			for (auto i{ 0U }; i < init_size; ++i)
			{
				tmp[i] = p[i];
			}
			delete[] p;
			p = tmp;
		}

		if (isspace(c))
		{
			p[length] = '\0';
			break;
		}
		else
		{
			p[length] = c;
			++length;
		}
	}

	if (length > 0U)
	{
		std::cout << std::string(p) << std::endl;
	}
	else
	{
		std::cout << "No word" << std::endl;
	}
	delete[] p;

	return 0;
}