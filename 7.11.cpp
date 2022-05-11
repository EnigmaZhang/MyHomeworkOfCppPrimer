#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data a{ Sales_data() };
	print(std::cout, a) << std::endl;
	
	Sales_data b{ Sales_data("123456") };
	print(std::cout, b) << std::endl;

	Sales_data c{ Sales_data("123456", 1, 2.0) };
	print(std::cout, c) << std::endl;

	Sales_data d{ Sales_data(std::cin) };
	print(std::cout, d) << std::endl;

	return 0;
}
