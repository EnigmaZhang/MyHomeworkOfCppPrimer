#include <iostream>
#include <sstream>
#include <string>

std::istream& f(std::istream& is);

int main()
{
	std::string s("Hello world!");
	std::istringstream iss(s);

	f(iss);

	std::cin >> s;
	std::cout << s;

	return 0;
}

std::istream& f(std::istream& is)
{
	while (is)
	{
		std::string s;
		is >> s;
		std::cout << s;
	}
	is.clear();
	return is;
}