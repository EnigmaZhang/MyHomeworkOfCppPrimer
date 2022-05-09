#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
	Sales_data data;

	std::cout << data.bookNo << "\t" << data.revenue << "\t" << data.units_sold << std::endl;

	return 0;
}