#include <set>
#include "Sales_data.h"

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs);

int main()
{
	Sales_data i;
	std::multiset <Sales_data, bool (*) (const Sales_data&, const Sales_data&)> bookstore{ compareIsbn };
	bookstore.insert(bookstore.begin(), i);
	for (const auto& book : bookstore)
	{
		print(std::cout, book);
		std::cout << std::endl;
	}

	return 0;
}