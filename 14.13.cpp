#include <string>
#include <iostream>

#include "Sales_data.h"


int main()
{
	Sales_data d1{ "a",1,0.1 };
	Sales_data d2{ "a",2,0.2 };

	std::cout << d1 + d2 << std::endl;
	std::cout << d1 - d2 << std::endl;
	std::cout << d2 - d1 << std::endl;

	return 0;
}