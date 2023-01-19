#include <string>
#include <iostream>

#include "Str_Vec.h"

int main()
{
	StrVec v;
	v.push_back("Hello");
	v.push_back("World");
	v.push_back("HHH");

	std::cout << v.capacity() << " " << v.size() << std::endl;

	v.resize(5);

	std::cout << v.capacity() << " " << v.size() << std::endl;
	v.reserve(10);

	std::cout << v.capacity() << " " << v.size() << std::endl;

	v.resize(1);
	std::cout << v.capacity() << " " << v.size() << std::endl;

	return 0;
}