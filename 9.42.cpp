#include <iostream>
#include <vector>

int main()
{
	std::string s;
	s.resize(100);

	char c;
	while (std::cin.get(c))
	{
		s.push_back(c);
	}
	std::cout << s << std::endl;

	return 0;
}