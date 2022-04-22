#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string last;
	std::string s;
	bool repeated{ false };

	while (std::cin >> s)
	{
		if (islower(s[0]))
		{
			continue;
		}

		if (s == last)
		{
			std::cout << s << " occurs twice in succession" << std::endl;
			repeated = true;
			break;
		}
		else
		{
			last = s;
		}
	}

	if (!repeated)
	{
		std::cout << "No word was repeated" << std::endl;
	}

	return 0;
}