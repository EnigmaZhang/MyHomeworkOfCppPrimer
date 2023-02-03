#include <string>
#include <iostream>

#include "Sales_data.h"


int main()
{
	Sales_data d("hello", 1, 4.0);

	std::cout << d << std::endl;

	return 0;
}