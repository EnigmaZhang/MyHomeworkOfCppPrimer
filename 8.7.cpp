#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Sales_data.h"

int main(int argc, char* argv[])
{
	Sales_data total = Sales_data();
	if (argc != 3)
	{
		throw std::runtime_error("No file name as argument");
	}
	auto ifs{ std::ifstream(argv[1]) };
	auto ofs{ std::ofstream(argv[2]) };

	if (read(ifs, total))
	{
		Sales_data transaction;
		while (read(ifs, transaction))
		{
			if (total.isbn() == transaction.isbn())
			{
				total.combine(transaction);
			}
			else
			{
				print(ofs, total) << std::endl;
				total = transaction;
			}
		}
		print(ofs, total);
	}
	else
	{
		std::cerr << "No data?!" << std::endl;
	}

	return 0;
}