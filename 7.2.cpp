#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data data = Sales_data("123456, 5, 0.8");

	std::cout << data.avg_price() << std::endl;
	std::cout << data.isbn() << std::endl;

	Sales_data another = Sales_data("123456, 1, 6.5");

	std::cout << data.combine(another).avg_price() << std::endl;

	return 0;
}
