#include <string>
#include <iostream>

#include "Str_Vec.h"

int main()
{
	StrVec v{ "aaa", "bbb", "ccc"};

	std::cout << v.capacity() << " " << v.size() << std::endl;

	return 0;
}