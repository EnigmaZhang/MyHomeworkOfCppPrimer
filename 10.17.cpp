#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Sales_data.h"

int main()
{
	std::vector<Sales_data>v{ Sales_data("123"), Sales_data("456"), Sales_data("123") };

	std::sort(v.begin(), v.end(), 
		[](const Sales_data& s1, const Sales_data& s2) { return s1.isbn() < s2.isbn(); });
	std::for_each(v.cbegin(), v.cend(), 
		[](const Sales_data& s) { print(std::cout, s); std::cout << std::endl; });

	return 0;
}