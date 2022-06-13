#include <iostream>
#include <fstream>
#include <algorithm>

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		throw new std::runtime_error("There should be 4 args");
	}

	std::ifstream ifs{ argv[1] };
	std::ofstream ofs1{ argv[2] };
	std::ofstream ofs2{ argv[3] };

	std::istream_iterator<int> is_iter{ ifs };
	std::istream_iterator<int> eof_iter;
	std::ostream_iterator<int> os_iter1{ ofs1, " " };
	std::ostream_iterator<int> os_iter2{ ofs2, "\n" };

	while (is_iter != eof_iter)
	{
		if (*is_iter % 2 == 1)
		{
			*os_iter1++ = *is_iter++;
		}
		else
		{
			*os_iter2++ = *is_iter++;
		}
	}

	return 0;
}