#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::vector<std::string> v;
	std::istream_iterator<std::string> is_iter{ std::cin }, eof_iter;
	while (is_iter != eof_iter)
	{
		v.push_back(*is_iter++);
	}
	std::sort(v.begin(), v.end());

	std::ostream_iterator<std::string> os_iter{ std::cout, " " };
	std::unique_copy(v.cbegin(), v.cend(), os_iter);

	return 0;
}