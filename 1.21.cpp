#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item a, b;

	std::cin >> a >> b;

	if (a.isbn() == b.isbn())
	{
		std::cout << a + b << std::endl;
	}
	else
	{
		std::cout << "The isbn of two books are not equal" << std::endl;
	}

	return 0;
}