#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

#include "Sales_item.h"

int main()
{
	std::vector<Sales_item> transactions;

	std::istream_iterator<Sales_item> is_iter{ std::cin };
	std::istream_iterator<Sales_item> eof_iter;

	while (is_iter != eof_iter)
	{
		transactions.push_back(*is_iter++);
	}
	if (transactions.size() == 0)
	{
		std::cerr << "No data?!" << std::endl;
		return -1;
	}

	std::sort(transactions.begin(), transactions.end(),
		[](const Sales_item& a, const Sales_item& b) { return a.isbn() < b.isbn(); });

	auto total{ transactions.cbegin() };
	while (total != transactions.cend())
	{
		std::cout << std::accumulate(total + 1, std::find_if(total, transactions.cend(),
			[&total](const Sales_item& i) {return i.isbn() != total->isbn(); }), *total) << std::endl;
		total = std::find_if(total, transactions.cend(),
			[&total](const Sales_item& i) {return i.isbn() != total->isbn(); });
	}

	return 0;
}