#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item sum;
	Sales_item item;
	bool same_isbn = true;

	std::cin >> sum;

	while (std::cin >> item)
	{
		if (item.isbn() != sum.isbn())
		{
			std::cout << "ISBN is not eqaul" << std::endl;
			same_isbn = false;
			break;
		}
		sum += item;
	}

	if (same_isbn)
	{
		std::cout << sum << std::endl;
	}

	return 0;
}