#include <iostream>
#include <string>

int main()
{
	do
	{
		std::string s1;
		std::string s2;
		
		std::cin >> s1;
		std::cin >> s2;

		if (s1.empty() && s2.empty())
		{
			;
		}
		else if (s1.empty() || s2.empty())
		{
			std::cout << "There is an EOF between two strings" << std::endl;
		}
		else if (s1 == s2)
		{
			std::cout << s1 << " is the same as " << s2 << std::endl;
		}
		else
		{
			std::cout << (s1 < s2 ? s1 : s2) << " is less than " << (s1 < s2 ? s2 : s1) << std::endl;
		}
	} while (std::cin.get() != EOF);

	return 0;
}