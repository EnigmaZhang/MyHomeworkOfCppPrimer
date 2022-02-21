#include <iostream>
#include <string>

struct Sales_data {
	std::string bookNo;
	unsigned int units_gold{ 0 };
	double revenue{ 0.0 };
};

Sales_data accum, trans, * salesptr;

int main()
{
	return 0;
}