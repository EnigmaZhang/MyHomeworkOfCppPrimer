#include <iostream>
#include <vector>

int main()
{
	std::string s;
	s.resize(100);

	while (std::cin)
	{
		char c;
		c = static_cast<char>(std::cin.get());
		s.push_back(c);
	}
	
	return 0;
}