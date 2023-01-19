#include <string>
#include <iostream>

#include "New_String.h"

int main()
{
	String s{ "hello world" };
	
	std::cout << s.size() << " " << s.capacity() << std::endl;
	s.push_back('h');
	s.push_back('o');
	s.reserve(99);
	std::cout << s.size() << " " << s.capacity() << std::endl;
	s.resize(0);
	std::cout << s.size() << " " << s.capacity() << std::endl;

	return 0;
}