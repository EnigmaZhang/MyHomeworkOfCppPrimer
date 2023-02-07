#include <string>
#include <iostream>

#include "Str_Vec.h"


int main()
{
	StrVec s;

	s = { "aaa","bbb","ccc" };

	for (const std::string* p{ s.begin() }; p != s.end(); ++p)
	{
		std::cout << *p << ' ';
	}
	std::cout << std::endl;

	return 0;
}