#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data total = Sales_data();
	
	if (read(std::cin, total))
	{
		Sales_data transaction;
		while (read(std::cin, transaction))
		{
			if (total.isbn() == transaction.isbn())
			{
				total.combine(transaction);
			}
			else
			{
				print(std::cout, total) << std::endl;
				total = transaction;
			}
		}
		print(std::cout, total);
	}
	else
	{
		std::cerr << "No data?!" << std::endl;
	}

	return 0;
}
