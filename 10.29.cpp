#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::vector<std::string> v;
	std::ifstream ifs{ "./10.29.txt" };
	std::istream_iterator<std::string> is_iter{ ifs }, eof_iter;
	while (is_iter != eof_iter)
	{
		v.push_back(*is_iter++);
	}

	std::ostream_iterator<std::string> os_iter{ std::cout, " " };
	std::copy(v.cbegin(), v.cend(), os_iter);

	return 0;
}