#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data data = Sales_data();
	data.bookNo = "123456";
	data.revenue = 4.0;
	data.units_sold = 5;

	std::cout << data.avg_price() << std::endl;
	std::cout << data.isbn() << std::endl;

	Sales_data another = Sales_data();
	another.bookNo = "123456";
	another.revenue = 6.5;
	another.units_sold = 1;

	std::cout << data.combine(another).avg_price() << std::endl;

	return 0;
}
