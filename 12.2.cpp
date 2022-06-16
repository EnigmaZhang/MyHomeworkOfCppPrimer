#include <iostream>

#include "Str_Blob.h"

int main()
{
	StrBlob b{ "a", "b", "c" };
	std::cout << b.front() << std::endl;
	std::cout << b.back() << std::endl;

	return 0;
}