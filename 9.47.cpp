#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string s{ "ab2c3d7R4E6" };
	std::string nums{ "0123456789" };
	std::string alphabet;
	for (char c{ 'a' }; c < 'z'; ++c)
	{
		alphabet += c;
		alphabet += static_cast<char>(toupper(c));
	}
	std::string::size_type pos{ 0 };

	while ((pos = s.find_first_of(nums, pos)) != std::string::npos)
	{
		std::cout << s[pos] << ' ';
		++pos;
	}
	std::cout << std::endl;
	pos = 0;

	while ((pos = s.find_first_of(alphabet, pos)) != std::string::npos)
	{
		std::cout << s[pos] << ' ';
		++pos;
	}
	std::cout << std::endl;
	pos = 0;

	while ((pos = s.find_first_not_of(alphabet, pos)) != std::string::npos)
	{
		std::cout << s[pos] << ' ';
		++pos;
	}
	std::cout << std::endl;
	pos = 0;

	while ((pos = s.find_first_not_of(nums, pos)) != std::string::npos)
	{
		std::cout << s[pos] << ' ';
		++pos;
	}

	return 0;
}
