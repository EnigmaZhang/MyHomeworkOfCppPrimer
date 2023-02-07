#include <string>
#include <iostream>

#include "New_String.h"


int main()
{
	String s1{ "Hello" }, s2{ "Hello" }, s3{ "hello" }, s4{ "Hell" };

	std::cout << (s1 < s2) << ' ' <<
		(s1 <= s2) << ' ' <<
		(s1 < s3) << ' ' <<
		(s1 <= s3) << ' ' <<
		(s1 > s3) << ' ' <<
		(s1 >= s3) << ' ' <<
		(s1 < s4) << ' ' <<
		(s1 <= s4) << ' ' <<
		(s1 > s4) << ' ' <<
		(s1 >= s4) << ' ' << std::endl;

	return 0;
}