#include <string>
#include <iostream>

#include "Sales_data.h"


int main()
{
	Sales_data s1{ "a", 1, 0.1 }, s2{ "a",2,0.2 };

	s1 += s2;

	std::cout << s1 << std::endl;

	return 0;
}