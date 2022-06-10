#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Sales_data.h"

bool compareIsbn(const Sales_data& s1, const Sales_data& s2);

int main()
{
	std::vector<Sales_data>v{ Sales_data("123"), Sales_data("456"), Sales_data("123") };

	std::sort(v.begin(), v.end(), compareIsbn);
	for (const auto& s : v)
	{
		print(std::cout, s);
		std::cout << std::endl;
	}

	return 0;
}

bool compareIsbn(const Sales_data& s1, const Sales_data& s2)
{
	return s1.isbn() < s2.isbn();
}
